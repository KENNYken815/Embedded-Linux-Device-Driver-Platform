#include "gateway.h"
#include "protocol.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern void logger_info(const char *message);
extern int serial_open(const char *device, int baud);
extern ssize_t serial_read_line(int fd, char *buffer, size_t size);

static gateway_context_t *g_ctx = NULL;

static void handle_signal(int signum)
{
    (void)signum;
    if (g_ctx != NULL) g_ctx->running = 0;
}

void gateway_init(gateway_context_t *ctx)
{
    memset(ctx, 0, sizeof(*ctx));
    ctx->running = 1;
    g_ctx = ctx;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
}

void gateway_shutdown(gateway_context_t *ctx)
{
    ctx->running = 0;
    g_ctx = NULL;
}

int gateway_run(gateway_context_t *ctx, const char *serial_device)
{
    int fd = serial_open(serial_device, 115200);

    if (fd < 0) {
        logger_info("Serial unavailable; running protocol demo.\n");

        telemetry_t demo = {42.5, 1200, "OK"};
        char payload[128];

        if (protocol_format(&demo, payload, sizeof(payload)) != 0)
            return -1;

        logger_info(payload);
        return 0;
    }

    logger_info("Gateway started.\n");
    char line[256];

    while (ctx->running) {
        ssize_t n = serial_read_line(fd, line, sizeof(line));

        if (n > 0) {
            telemetry_t data;

            if (protocol_parse(line, &data) == 0) {
                char normalized[128];
                protocol_format(&data, normalized, sizeof(normalized));
                logger_info(normalized);
            } else {
                logger_info("Invalid telemetry packet received.\n");
            }
        }

        usleep(10000);
    }

    close(fd);
    logger_info("Gateway stopped.\n");
    return 0;
}
