
#include "monty.h"


void op_code(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i = 0;
	char *cmp;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (op[i].op_code)
	{
		cmp = malloc(sizeof(*cmp) * strlen(op[i].op_code) + 1);
		memcpy(cmp, str, strlen(op[i].op_code));
		cmp[strlen(cmp)] = 0;
		if (strcmp(op[i].op_code, cmp) == 0)
		{
			op[i].f(stack, line_cnt);
			free(cmp);
			return; /* if we found a match, run the function */
		}
		i++;
		free(cmp);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
}