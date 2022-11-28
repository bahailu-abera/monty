#include "monty.h"

/**
 * mod - computes the rest of the _division of the second top
 * element of the stack by the top element of the stack
 *
 * @stack: the stack data structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	node->next->n = (node->next->n) % (node->n);
	(*stack) = node->next;
	free(node);
	node = NULL;
}
