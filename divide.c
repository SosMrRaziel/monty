#include "monty.h"

/**
 * divide - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: The stack
 * @ln: The line number
 *
 * Return: Nothing
 */

void divide(stack_t **stack, unsigned int ln)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
		;
		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, ln);
	(*stack)->n = result;
}
