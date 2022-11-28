#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack data structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = node->n;
	node->n = node->next->n;
	node->next->n = n;
}
