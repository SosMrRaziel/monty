#include "monty.h"

/**
 * pall - prints all the elements of the stack
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 */


void pall(stack_t **stack, unsigned int ln)
{
	stack_t *temp = *stack;
	(void)ln;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
