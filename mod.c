#include "monty.h"

/**
 * module - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 */

void module(stack_t **stack, unsigned int ln)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n  == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, ln);
	(*stack)->n = result;
}
