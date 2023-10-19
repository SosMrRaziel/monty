#include "monty.h"




/**
 * _pop - removes the top element of the stack
 *
 * @stack: a double pointer to the top of the stack
 * @ln: the line number in monty file
 */
/*
void pop(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
*/

void pop(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}