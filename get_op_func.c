#include "monty.h"

/**
 * get_op_func - selects the correct function for the operation
 * @stack: the stack data structure
 * @line_number: the current reading line number in the input file
 *
 * Return: the selected function
 */
void  (*get_op_func(stack_t *stack, unsigned int line_number))(stack_t **stack,
							       unsigned int line_number)
{
	unsigned int i;
	instruction_t oper[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};

	for (i = 0; oper[i].opcode != NULL; i++)
	{
		if (strcmp(oper[i].opcode, stream.token) == 0)
		{	return (oper[i].f);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, stream.token);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
