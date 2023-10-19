#include "monty.h"

void execute_func(FILE *my_file)
{
    char *line = NULL;
    char *tokenizer;
    unsigned int line_number = 1;
    size_t size = 0;
    ssize_t read_line;

    stack_t *stack = NULL;

    while ((read_line = getline(&line, &size, my_file)) != -1)
    {
        tokenizer = strtok(line, " \n\t");
        if (tokenizer == NULL)
        {
            line_number++;
            continue;
        }

        get_oper(&stack, line_number, tokenizer);
        line_number++;
    }

    free_stack(stack);
    free(line);
    fclose(my_file);
}