#include "monty.h"

/**
 * get_oper - get the corresponding operation code
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 * @my_op: the opcode in the file
 */

void get_oper(stack_t **stack, unsigned int ln, char *my_op)
{
	instruction_t oper[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", multiply},
		{"mod", module},
		{"pchar", p_char},
		{"pstr", put_str},
		{NULL, NULL}
	};

	int i = 0;

	while (oper[i].opcode != NULL)
	{
		if (strcmp(oper[i].opcode, my_op) == 0)
		{
			oper[i].f(stack, ln);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", ln, my_op);
	free_db_list(*stack);
	exit(EXIT_FAILURE);
}
