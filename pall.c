#include "monty.h"

/**
 * pall - stack method that prints the stack
 * @stack: the stack data structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)line_number;
	for (; head != NULL; head = head->next)
		printf("%d\n", head->n);
}
