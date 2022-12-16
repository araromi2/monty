#include "monty.h"

/**
 * tokenize - tokenizes a string
 * @line: string to tokenize
 * Return: array of tokens
 */
char **tokenize(char *line)
{
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 3);
	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n");
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\r\n");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_stack - frees a stack
 * @stack: pointer to the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * free_all - frees all
 * @stack: pointer to the stack
 * @line: line to free
 * @fp: file pointer
 * @tokens: array of tokens
 */
void free_all(stack_t *stack, char *line, FILE *fp, char **tokens)
{
	free_stack(stack);
	free(line);
	free(tokens);
	fclose(fp);
}

/**
 * get_op - gets the opcode function
 * @stack: double pointer to the stack
 * @line: line to print in case of error
 * @line_number: line number
 * @tokens: array of tokens
 */
void get_op(stack_t **stack, char *line,
		unsigned int line_number, char **tokens)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, tokens[0]) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, tokens[0]);
	free_all(*stack, line, NULL, tokens);
	exit(EXIT_FAILURE);
}
