#include "monty.h"

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 *  @stack: a double pointer to the to of the stack
 *  @ln: the line number is monty file
 */

void sub(stack_t **stack, unsigned int ln)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, ln);
	(*stack)->n = result;
}
