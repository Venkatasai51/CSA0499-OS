#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    int fd, n;
    char buf[100];
    fd = open("test.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    n = write(fd, "Hello, world!\n", 14);
    if (n == -1)
    {
        perror("write");
        return 1;
    }
    n = lseek(fd, 0, SEEK_SET);
    if (n == -1)
    {
        perror("lseek");
        return 1;
    }
    n = read(fd, buf, 100);
    if (n == -1)
    {
        perror("read");
        return 1;
    }
    write(1, buf, n);
    n = close(fd);
    if (n == -1)
    {
        perror("close");
        return 1;
    }
    return 0;
}

