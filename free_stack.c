#include "monty.h"

void free_stack(stack_t *stack)
{
    stack_t *tmp;

    while(stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}