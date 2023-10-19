#include "monty.h"

/**
 * free_dllist - free the doubly likned list
 *
 * @stack: the tof of the stack
 */

void free_dllist(stack_t *stack)
{
    if (stack == NULL) /* base case */
        return;
    free_dllist(stack->next); /* recursive call */
    free(stack); /* free the current node */
}