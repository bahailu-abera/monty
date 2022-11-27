#ifndef _MONTY_H
#define _MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack or a queue.
 * @n: integer
 * @prev: points to the previous element of the stack (or queue).
 * @next: points to the next element of the stack (or queue).
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
 * @f: function to handle its opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stream_s - a representation of stream at a line
 * @token: the first string before the delimeter
 * @value: the next string
 *
 * Description: token and value of the command line
 */
typedef struct
{
	char *token;
	char *value;
} stream_t;

/** decode the token into opcode and call the method **/
void (*get_op_func(stack_t *stack, unsigned int line_number))(stack_t **stack,
							   unsigned int line_number);

/** stack operation methods **/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
extern stream_t stream;

#endif
