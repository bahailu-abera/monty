#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: the stack data structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = (*stack);
	(*stack) = node->next;
	printf("%d\n", node->n);
	free(node);
	node = NULL;
}
