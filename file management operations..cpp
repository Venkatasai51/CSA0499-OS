#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    int fd, n;
    char buf[100];
    fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    n = write(fd, "This is a test file.\n", 21);
    if (n == -1)
    {
        perror("write");
        return 1;
    }
    n = close(fd);
    if (n == -1)
    {
        perror("close");
        return 1;
    }
    n = rename("test.txt", "new.txt");
    if (n == -1)
    {
        perror("rename");
        return 1;
    }
    fd = open("new.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    n = read(fd, buf, 100);
    if (n == -1)
    {
        perror("read");
        return 1;
    }
    write(STDOUT_FILENO, buf, n);
    n = close(fd);
    if (n == -1)
    {
        perror("close");
        return 1;
    }
    n = remove("new.txt");
    if (n == -1)
    {
        perror("remove");
        return 1;
    }

    return 0;
}

