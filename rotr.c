#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 *
 * @stack: the stack data structure
 * @line_number: the current reading line_number
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
	}

	if (node != NULL && node != *stack)
	{
		node->next = (*stack);
		node->prev->next = NULL;
		node->prev = NULL;
		(*stack) = node;
	}
}
