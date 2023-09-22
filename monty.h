#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024
#define LINE_SIZE 163

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct G_variables
{
	FILE *monty_file;
	char *buffer;
	char **cmd_op;
	stack_t *head;
} G_var;
extern G_var var;

size_t stack_len(const stack_t *h);
void free_stack(stack_t *head);
char **tokenize(char *delim);
void execute_op(unsigned int line);
void push_to_stack(stack_t **, unsigned int);
int is_integer(char *arg);
void print_all_stack(stack_t **, unsigned int);
void print_char_stack(stack_t **, unsigned int);
void print_first_stack(stack_t **, unsigned int);
void delete_first_stack(stack_t **, unsigned int);
void swap_two_stack(stack_t **, unsigned int);
void sum_two_stack(stack_t **, unsigned int);
void sub_two_stack(stack_t **, unsigned int);
void div_two_stack(stack_t **, unsigned int);
void mul_two_stack(stack_t **, unsigned int);
void mod_two_stack(stack_t **, unsigned int);
void no_action(stack_t **, unsigned int);

#endif
