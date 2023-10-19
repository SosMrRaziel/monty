#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 */

void swap(stack_t **stack, unsigned int ln)
{
	int tmp;
	stack_t **second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	second = &(*stack)->next; /* pointer to pointer to second node */
	tmp = (*stack)->n;
	(*stack)->n = (*second)->n;
	(*second)->n = tmp;
}
