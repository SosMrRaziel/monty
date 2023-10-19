#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the top element
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 */

void multiply(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= temp->n;
	free(temp);
}

/**
 * _mod - calcultes the remainder of division
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 */

void module(stack_t **stack, unsigned int line_number)
{
	int remainder;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n  == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	remainder = (*stack)->n % temp->n;
	(*stack)->n = remainder;
	free(temp);
}



/**
 * _pstr - prints the string starting at the top of the stack
 *
 * @stack: a double pointer to the stack
 * @line_number: the line number in monty file
 */

void put_str(stack_t **stack, unsigned int line_number)
{
	int *ptr;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	ptr = (int *)(*stack);

	while (*ptr > 0 && *ptr <= 127)
	{
		printf("%c", *ptr);
		ptr++;
	}
	printf("\n");
}