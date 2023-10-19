#include "monty.h"

/**
 * multiply - multiplies the second top element
 * of the stack with the top element
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 */

void multiply(stack_t **stack, unsigned int ln)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, ln);
	(*stack)->n = tmp;
}
