#include "monty.h"

char **tokens = NULL;
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fp) != -1)
	{
		line_number++;
		tokens = tokenize(line);
		if (tokens[0] && tokens[0][0] != '#')
			get_op(&stack, line, line_number, tokens);
		free(tokens);
	}
	free(line);
	free_stack(stack);
	fclose(fp);
	return (0);
}
