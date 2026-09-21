#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

int serial_open(const char *device, int baud)
{
    (void)baud;

    int fd = open(device, O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd < 0) return -1;

    struct termios tty;
    if (tcgetattr(fd, &tty) != 0) {
        close(fd);
        return -2;
    }

    cfmakeraw(&tty);
    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);
    tty.c_cflag |= (CLOCAL | CREAD);

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        close(fd);
        return -3;
    }

    return fd;
}

ssize_t serial_read_line(int fd, char *buffer, size_t size)
{
    size_t used = 0;

    while (used + 1 < size) {
        char c;
        ssize_t n = read(fd, &c, 1);

        if (n == 1) {
            buffer[used++] = c;
            if (c == '\n') break;
        } else if (n < 0 && (errno == EAGAIN || errno == EWOULDBLOCK)) {
            break;
        } else if (n < 0) {
            return -1;
        } else {
            break;
        }
    }

    buffer[used] = '\0';
    return (ssize_t)used;
}
