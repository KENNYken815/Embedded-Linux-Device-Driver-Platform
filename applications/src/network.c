#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdint.h>
#include <sys/socket.h>
#include <unistd.h>

int network_send_tcp(const char *host, int port, const char *payload)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) return -1;

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons((uint16_t)port);

    if (inet_pton(AF_INET, host, &addr.sin_addr) != 1) {
        close(fd);
        return -2;
    }

    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
        close(fd);
        return -3;
    }

    size_t len = 0;
    while (payload[len] != '\0') len++;

    ssize_t sent = send(fd, payload, len, 0);
    close(fd);

    return sent == (ssize_t)len ? 0 : -4;
}
