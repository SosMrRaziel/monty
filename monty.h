#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stddef.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include <stddef.h> 
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - op_code and its function
 * @op_code: the op_code
 * @f: function to handle the op_code
 *
 * Description: op_code and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *op_code;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_number);

void op_code(stack_t **stack, char *str, unsigned int line_cnt);
void error_usage(void);
void file_error(char *argv);

int isnumber(char *str);
int check_digit(char *arg);

stack_t *add_node(stack_t **head, const int n);
size_t print_stack(const stack_t *head);

#endif /* MONTY_H */