#include "monty.h"


/**
 * _mod - calcultes the remainder of division
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 */

void module(stack_t **stack, unsigned int ln)
{
	int remainder;
	stack_t *tmp;

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

	tmp = *stack;
	*stack = (*stack)->next;
	remainder = (*stack)->n % tmp->n;
	(*stack)->n = remainder;
	free(tmp);
}