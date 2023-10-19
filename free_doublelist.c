#include "monty.h"

/**
 * free_db_list - free the doubly likned list
 *
 * @stack: the tof of the stack
 */

void free_db_list(stack_t *stack)
{
	if (stack == NULL)
		return;
	free_db_list(stack->next);
	free(stack);
}
