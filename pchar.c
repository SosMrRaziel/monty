#include "monty.h"

/**
 * p_char - prints the char at the top of the stack, followed by a new line.
 *
 * @stack: a double pointer to the top of the stack
 * @ln: the line number in monty file
 */

void p_char(stack_t **stack, unsigned int ln)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
