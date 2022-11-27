#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include "monty.h"

stream_t stream;

/**
 * parse - lexical analyzer of the source code
 * @file: the name of the source code file
 *
 * Return: void
 */
void parse(char *file)
{
	FILE *fin;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *delim = " \n";
	unsigned int line_number = 0;
	void (*f)(stack_t **, unsigned int);
	stack_t *stack = NULL;

	stream.token = NULL;
	stream.value = NULL;
	fin = fopen(file, "r");
	if (fin == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, fin)) != EOF)
	{
		line_number += 1;

		stream.token = strtok(line, delim);
		stream.value = strtok(NULL, delim);

		if (nread == 1 || stream.token == NULL)
			continue;
		f = get_op_func(stack, line_number);
		(*f)(&stack, line_number);
	}
	free(line);
	fclose(fin);
	free_stack(stack);
}

/**
 * main - checks the length of command line args and parse the source file
 * if there is one in the command line
 * @argc: the length of the command line argument
 * @argv: array of command line arguments
 *
 * Return: 1 (success) or 0 (failure)
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	parse(argv[1]);

	return (EXIT_SUCCESS);
}
