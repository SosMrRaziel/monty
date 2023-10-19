#include "monty.h"


/**
 * _div - divides the second top element of the stack by the top element
 *
 * @stack: a double pointer to the top of the stack
 * @ln: the line number in monty file
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

