#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *n = tokens[1];

	if (!n)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	while (*n)
	{
		if (*n < '0' || *n > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_all(*stack, NULL, NULL, tokens);
			exit(EXIT_FAILURE);
		}
		n++;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(tokens[1]);
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	if (tmp->next)
		tmp->next->prev = tmp;
}
