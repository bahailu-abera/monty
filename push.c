#include "monty.h"

/**
 * push - stack operation that pushs value to the top of the stack
 * @stack: the stack data sstructure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (stream.value == NULL || !isdigit(*(stream.value)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(stream.value);
	new->prev = NULL;
	new->next = (*stack);
	if (*stack != NULL)
		(*stack)->prev = new;
	(*stack) = new;
}
