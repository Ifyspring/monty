#include "monty.h"
/**
 *
 *
 *
 */
void Func_swap(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int temp;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	prev =  dir->prev;
	temp  = prev->n;
	prev->n = dir->n;
	dir->n = temp;
}
/**
 *
 *
 */
void Func_add(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	prev = dir->prev;
	result =  prev->n + dir->n;
	prev->n = result;
	free(dir);
	prev->next = NULL;
}
/**
 *
 */
void Func_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
/**
 *
 */
void Func_sub(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	prev = dir->prev;
	result =  (prev->n) - (dir->n);
	prev->n = result;
	free(dir);
	prev->next = NULL;
}
/**
 *
 *
 */
void Func_div(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	if (!dir->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	prev = dir->prev;
	result = (prev->n) / (dir->n);
	prev->n = result;
	free(dir);
	prev->next = NULL;
}
