#include "main.h"

arg_s *arg = NULL;

int main(int argc, char **argv)
{
    size_t n = 0;

    if (argc != 2)
    {
        dprintf(2, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    init_args(argc);
    read_file(argv[1]);

    while (getline(&arg->line, &n, arg->ptr) != -1)
    {
        printf("%s", arg->line);
    }
    return 0;
}
