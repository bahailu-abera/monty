#include "monty.h"

/**
 * _atoi - converts a string into integer
 * @string: the string to be converted
 * @flag: flag for exist
 * Return: the integer (on success) exit (on failure)
 */
int _atoi(char *string, int *flag)
{
	int num = 0, parity = 1;

	if (string == NULL || *string == '\0')
	{
		*flag = 1;
		return (num);
	}
	while (isspace(*string))
		string++;
	if (*string == '-')
		parity = -1, string++;
	else if (*string == '+')
		string++;
	while (isdigit(*string))
		num = (num * 10) + (*string - '0'), string++;
	if (*string == '\0' || isspace(*string))
		return (parity * num);
	*flag = 1;
	return (num);
}
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
	int flag = 0, value;

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = _atoi(stream.value, &flag);
	if (stream.value == NULL || flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = (*stack);
	if (*stack != NULL)
		(*stack)->prev = new;
	(*stack) = new;
	if (stream.df == 1) /** it queue data structure **/
		rotl(stack, line_number);
}
