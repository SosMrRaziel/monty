
#include "monty.h"


/*
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = strtok(NULL, " \t\n");

	if (!isdigit(*n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	if (!add_node(stack, atoi(n)))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
*/

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
  char *arg;
  int n;

  arg = strtok(NULL, "\n\t\r "); /* get the argument after "push" */
  if (arg == NULL || check_digit(arg) == 0) /* check if argument is valid */
  {
    fprintf(stderr, "L%d: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
  }
  n = atoi(arg); /* convert argument to integer */
  add_node(stack, n); /* add node to the stack */
}

