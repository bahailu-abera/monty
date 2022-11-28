#include "monty.h"

/**
 * data_format - inverts the format of the data
 * @stack: the stack datat structure
 * @line_number: the current reading line number
 *
 * Return: void
 */
void data_format(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	stream.df ^= 1;
}
