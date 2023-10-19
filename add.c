#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: A pointer to the head of the stack.
 * @ln: The line number of the opcode being executed.
 *
 * Return: Nothing.
 */

void add(stack_t **stack, unsigned int ln)
{
	stack_t *top, *second;
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	sum = top->n + second->n;
	second->n = sum;
	free(top);
	*stack = second;
}
