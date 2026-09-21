#include "gateway.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    const char *device = (argc > 1) ? argv[1] : "/dev/ttyS0";

    gateway_context_t ctx;
    gateway_init(&ctx);

    printf("Embedded Linux Industrial Gateway\n");
    printf("Serial: %s\n", device);

    int rc = gateway_run(&ctx, device);

    gateway_shutdown(&ctx);
    return rc;
}
