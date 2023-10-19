#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 *
 * @stack: a double pointer to the top of the stack
 * @ln: the line number in monty file
 */
/*
void pint(stack_t **stack, unsigned int ln)
{
	stack_t *top = *stack;
	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
*/


void pint(stack_t **stack, unsigned int ln)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}