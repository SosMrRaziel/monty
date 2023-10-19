#include "monty.h"

/**
 * put_str - prints the string starting at the top of the stack
 *
 * @stack: a double pointer to the stack
 * @ln: the line number in monty file
 */

void put_str(stack_t **stack, unsigned int ln)
{
	int *ptr;
	(void)ln;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	ptr = (int *)(*stack);

	while (*ptr > 0 && *ptr <= 127)
	{
		printf("%c", *ptr);
		ptr++;
	}
	printf("\n");
}
