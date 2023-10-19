#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;

void push(stack_t **stack, unsigned int ln);
void pall(stack_t **stack, unsigned int ln);
void pint(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int ln);
void sub(stack_t **stack, unsigned int ln);
void divide(stack_t **stack, unsigned int ln);
void multiply(stack_t **stack, unsigned int ln);
void module(stack_t **stack, unsigned int ln);
void p_char(stack_t **stack, unsigned int ln);
void put_str(stack_t **stack, unsigned int ln);
void execute_func(FILE *my_file);
void get_opcode(stack_t **stack, unsigned int ln, char *opc);
void free_db_list(stack_t *stack);

#endif
