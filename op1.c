#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 */

void swap(stack_t **stack, unsigned int ln)
{
	int tmp;
	stack_t **second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	second = &(*stack)->next; /* pointer to pointer to second node */
	tmp = (*stack)->n;
	(*stack)->n = (*second)->n;
	(*second)->n = tmp;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number of monty file
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

/**
 * _nop - doesn’t do anything
 *
 * @stack: a double pointer to the top of the stack
 * @ln: the line number in monty file
 */
void nop(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}

/**
 *  _sub - subtracts the top element from the second top element of the stack
 *
 *  @stack: a double pointer to the to of the stack
 *  @ln: the line number is monty file
 */

void sub(stack_t **stack, unsigned int ln)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, ln);/*For top node*/
	(*stack)->n = result;
}


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

