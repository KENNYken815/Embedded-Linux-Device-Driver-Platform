#ifndef GATEWAY_H
#define GATEWAY_H
#include <signal.h>
typedef struct {
    volatile sig_atomic_t running;
} gateway_context_t;
void gateway_init(gateway_context_t *ctx);
void gateway_shutdown(gateway_context_t *ctx);
int gateway_run(gateway_context_t *ctx, const char *serial_device);
#endif
