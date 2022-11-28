#include "monty.h"

/**
 * _div - divides the second top element of the stack
 * by the second top element of the stack
 *
 * @stack: the stack data structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't _div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (node->n == 0)
	{
		fprintf(stderr, "L%d: _division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	node->next->n = (node->next->n) / (node->n);
	(*stack) = node->next;
	free(node);
	node = NULL;
}
