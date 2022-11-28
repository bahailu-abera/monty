#include "monty.h"

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: the stack data structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node->next->n = (node->next->n) - (node->n);
	*(stack) = node->next;
	free(node);
	node = NULL;
}
