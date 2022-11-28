#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: the stack data structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node->next->n = (node->n) + (node->next->n);
	*(stack) = node->next;
	free(node);
	node = NULL;
}
