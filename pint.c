#include "monty.h"

/**
 * pint - prints the value of the top of stack followed by new line
 * @stack: the stack data structure
 * @line_number: the current reading line
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	(*stack) = (*stack)->next;
	printf("%d\n", node->n);
	free(node);
	node = NULL;
}
