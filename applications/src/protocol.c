#include "protocol.h"
#include <stdio.h>

int protocol_parse(const char *line, telemetry_t *out)
{
    if (!line || !out) return -1;

    double temperature;
    int rpm;
    char state[16] = {0};

    if (sscanf(line, "TEMP=%lf;RPM=%d;STATE=%15[^\n\r]",
               &temperature, &rpm, state) != 3) {
        return -2;
    }

    if (temperature < -100.0 || temperature > 200.0 ||
        rpm < 0 || rpm > 100000) {
        return -3;
    }

    out->temperature = temperature;
    out->rpm = rpm;
    snprintf(out->state, sizeof(out->state), "%s", state);
    return 0;
}

int protocol_format(const telemetry_t *data, char *buffer, size_t size)
{
    if (!data || !buffer || size == 0) return -1;

    int n = snprintf(buffer, size,
                     "TEMP=%.2f;RPM=%d;STATE=%s\n",
                     data->temperature, data->rpm, data->state);

    return (n < 0 || (size_t)n >= size) ? -2 : 0;
}
