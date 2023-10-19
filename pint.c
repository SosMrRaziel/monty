#include "monty.h"

/**
 * pint -  prints the value at the top of the stack,
 * followed by a new line.
 * @stack: a double pointer to the top of the stack
 * @ln: the line number in monty file
 */

void pint(stack_t **stack, unsigned int ln)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}
