#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 *
 * @stack: a double pointer to the top of the stack
 * @ln: the line number in monty file
 */


/*

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_dllist(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}


*/


/**
 * _pchar - prints the char at the top of the stack
 *
 * @stack: a double pointer to the top of the stack
 * @ln: the line number in monty file
 */


void p_char(stack_t **stack, unsigned int ln)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}