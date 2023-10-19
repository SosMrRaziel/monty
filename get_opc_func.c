#include "monty.h"

/**
 * get_opcode - get the corresponding opcode
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 * @opc: the opcode in the file
 */

void get_opcode(stack_t **stack, unsigned int ln, char *opc)
{
	instruction_t operations[] = {
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

	while (operations[i].opcode != NULL)
	{
		if (strcmp(operations[i].opcode, opc) == 0)
		{
			operations[i].f(stack, ln);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", ln, opc);
	free_db_list(*stack);
	exit(EXIT_FAILURE);
}
