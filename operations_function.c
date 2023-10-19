#include "monty.h"

void get_oper(stack_t **stack, unsigned int line_number, char *my_op)
{

    instruction_t oper[] = {
        {"push", _push},
        {"pall", _pall},
        {NULL, NULL}
    };

    int i = 0;

    while (oper[i].opcode)
    {
        if (strcmp(oper[i].opcode, my_op) == 0)
        {
            oper[i].f(stack, line_number);
            return;
        }
        /*else if (my_op != oper[i].op_code)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, my_op);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }*/
        i++;
    }

        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, my_op);
        free_stack(*stack);
        exit(EXIT_FAILURE);
}

    