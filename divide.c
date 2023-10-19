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
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	tmp = (*stack)->prev;
	(*stack)->prev = tmp->prev;
	free(tmp);
}
