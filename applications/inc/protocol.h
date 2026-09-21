#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <stddef.h>
typedef struct {
    double temperature;
    int rpm;
    char state[16];
} telemetry_t;
int protocol_parse(const char *line, telemetry_t *out);
int protocol_format(const telemetry_t *data, char *buffer, size_t size);
#endif
