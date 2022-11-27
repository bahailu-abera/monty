#include "monty.h"

/**
 * free_stack - frees the allocated memory for the stack
 * @stack: the stack data structue
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *node;

	while (stack)
	{
		node = stack;
		stack = node->next;
		free(node);
	}
}
