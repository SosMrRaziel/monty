#include "main.h"

void init_args()
{
    arg = malloc(sizeof(args));
    if (arg == NULL)
    {
        dprintf(2, "Error: malloc failed\n");
        free(arg);
        exit(EXIT_FAILURE);
    }

    arg->ptr = NULL;
    arg->line = NULL;
}