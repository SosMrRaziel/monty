#include "monty.h"

/**
 * _pall - prints all the elements of the stack
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}