#include "monty.h"

/**
 * _push - push a node to the top of the stack
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 */

void push(stack_t **stack, unsigned int ln)
{
	stack_t *new;
	int n;
	char *arg_token = strtok(NULL, " \n\t");

	if (arg_token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg_token);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}