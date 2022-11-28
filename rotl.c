#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: the stack data structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
	}
	if (node != NULL && *stack != node) /** the stack have more than one node **/
	{
		node->next = (*stack);
		(*stack)->prev = node;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		node->next->next = NULL;
	}
}
