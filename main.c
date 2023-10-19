#include "monty.h"

<<<<<<< HEAD
/**
 * main - Entry point
 *
 * Description: create an interpreter for Monty files
 * @ac: number of arguments
 * @av: a pointer to array
 * Return: 0 (Success)
 */

int main(int ac, char *av[])
{
	FILE *fd;
	char *m_file = av[1];

	if (ac != 2)
=======
int main(int argc, char *argv[])
{
    FILE *fd;
    char *my_file = argv[1];

    if (argc != 2)
>>>>>>> fati
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

<<<<<<< HEAD
	fd = fopen(m_file, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}

	execute(fd);

	return (0);
}
=======
    fd = fopen(my_file, "r");

    if (!fd)
    {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
    }

    execute_func(fd);

    return 0;
}
>>>>>>> fati
