#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the top element
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 */

void multiply(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= tmp->n;
	free(tmp);
}

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



/**
 * _pstr - prints the string starting at the top of the stack
 *
 * @stack: a double pointer to the stack
 * @ln: the line number in monty file
 */

void put_str(stack_t **stack, unsigned int ln)
{
	int *ptr;
	(void)ln;

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