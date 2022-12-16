#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n += tmp->n;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * nop - doesn’t do anything
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = tmp->n - (*stack)->n;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = tmp->n / (*stack)->n;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_all(*stack, NULL, NULL, tokens);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n *= tmp->n;
	(*stack)->prev = NULL;
	free(tmp);
}
