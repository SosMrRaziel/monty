#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number in monty file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t **second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	second = &(*stack)->next; /* pointer to pointer to second node */
	temp = (*stack)->n;
	(*stack)->n = (*second)->n;
	(*second)->n = temp;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @stack: a double pointer to the top of stack
 * @line_number: the line number of monty file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
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

/**
 * _nop - doesn’t do anything
 *
 * @stack: a double pointer to the top of the stack
 * @line_number: the line number in monty file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 *  _sub - subtracts the top element from the second top element of the stack
 *
 *  @stack: a double pointer to the to of the stack
 *  @line_number: the line number is monty file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	second = (*stack)->next;
	result = second->n - (*stack)->n;
	second->n = result;
	second->prev = NULL;
	free(*stack);
	*stack = second;
}


/**
 * _div - divides the second top element of the stack by the top element
 *
 * @stack: a double pointer to the top of the stack
 * @line_number: the line number in monty file
 */

void divide(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	temp = (*stack)->prev;
	(*stack)->prev = temp->prev;
	free(temp);
}

