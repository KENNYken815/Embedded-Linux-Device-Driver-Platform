#include <stdio.h>
#include <time.h>

void logger_info(const char *message)
{
    time_t now = time(NULL);
    struct tm tm_now;
    localtime_r(&now, &tm_now);

    char stamp[32];
    strftime(stamp, sizeof(stamp), "%Y-%m-%d %H:%M:%S", &tm_now);
    printf("[%s] %s", stamp, message);
}
