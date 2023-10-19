#include "monty.h"

/**
 * push - pushes an element to the stack.
 *
 * @stack: a double pointer to the top of stack
 * @ln: the line number in monty file
 */

void push(stack_t **stack, unsigned int ln)
{
	stack_t *new_node;
	int n;
	char *token = strtok(NULL, " \n\t");

	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		free_db_list(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(token);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
