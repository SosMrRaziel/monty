#include "monty.h"

/**
 * execute_func - read from the file and execute the corresponding opcode
 *
 * @my_file: the file to read from
 */

void execute_func(FILE *my_file)
{
	char *line = NULL;
	char *tokenizer;
	unsigned int ln = 1;
	size_t count = 0;
	ssize_t read_line;

	stack_t *stack = NULL;

	while ((read_line = getline(&line, &count, my_file)) != -1)
	{
		tokenizer = strtok(line, " \n\t");
		if (tokenizer == NULL)
		{
			ln++;
			continue;
		}

		get_oper(&stack, ln, tokenizer);
		ln++;
	}

	free_db_list(stack);
	free(line);
	fclose(my_file);
}
