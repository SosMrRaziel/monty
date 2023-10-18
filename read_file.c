#include "main.h"

void read_file_failed(char *file)
{
    dprintf(stderr, "Error: Can't open file %s\n", file);
    exit(EXIT_FAILURE);
}

void read_file(char * file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        read_file_failed(file);

    arg->ptr = fdopen(fd, "r");
    if (arg->ptr == NULL)
    {
        close(fd);
        read_file_failed(file);
    }
}
