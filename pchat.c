#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 *
 * @stack: a double pointer to the top of the stack
 * @line_number: the line number in monty file
 */


void p_char(STACK_NODE_T **stack, unsigned int line_number)
{
	int c;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n;
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(c);
	putchar('\n');
}