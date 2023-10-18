#include "monty.h"

/*
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);		
}

*/

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the instruction
 */



void pall(stack_t **stack, unsigned int line_number)
{
  stack_t *temp = *stack;
  (void)line_number;

  while (temp != NULL)
  {
    printf("%d\n", temp->n);
    temp = temp->next;
  }
}

