#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * followed by new line
 * @stack: the stack data structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;
	while (node)
	{
		if (node->n != 0 && isascii(node->n))
			printf("%c", node->n);
		else
			break;
		node = node->next;
	}
	printf("\n");
}
