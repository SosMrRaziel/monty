#include "monty.h"

/**
 * main - Entry point
 *
 * Description: create an interpreter for Monty files
 * @argc: number of arguments
 * @argv: a pointer to array of arguments
 * Return: 0 (Success)
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	char *my_file = argv[1];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(my_file, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	execute_func(fd);

	return (0);
}
