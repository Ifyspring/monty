#include "monty.h"
#include <ctype.h>
/**
 *
 *
 */
void Func_mul(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr,  "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	prev = dir->prev;
	result = (prev->n) * (dir->n);
	prev->n = result;
	free(dir);
	prev->next = NULL;
}
/**
 *
 *
 */
void Func_mod(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
	result = (prev->n) % (dir->n);
	prev->n = result;
	free(dir);
	prev->next = NULL;
}
/**
 * ErrorHandler - handle errors	 in the program
 * @error_number: unique error number for different error
 * @arg: string needle for the error
 *
 * Return: return void
 */
void ErrorHandler(int error_number, char *arg, int line_number)
{
	switch (error_number)
	{
		case 1:/* program argument error */
		{
			fprintf(stderr, "USAGE: monty %s\n", arg);
			EXIT;
			break;
		}
		case 2:/* open file error */
		{
			fprintf(stderr, "Error could'nt open file %s\n", arg);
			EXIT;
			break;
		}
		case 3:/* malloc error */
		{
			fprintf(stderr, "Error: malloc failed\n");
			EXIT;
			break;
		}
		case 4:/* opcode error (invalid instruction) */
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, arg);
			EXIT;
			break;
		}
		case 5:/* empty stack error */
		{
			fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
			EXIT;
			break;
		}
	}
}
/**
 *
 *
 */
void Func_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head;

	if (!CountStack(head))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	if (!isalpha(dir->n + 48))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", dir->n);
}
/**
 *
 *
 */
void Func_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head;
	int count = 0;

	(void)line_number;
	count = CountStack(head);
	if (!count)
		putchar('\n');
	while (dir->next)
		dir = dir->next;
	for (count = count; dir; dir = dir->prev, count--)
	{
		if (!count || !dir->n)
			goto next;
		printf("%c",  dir->n);
	}
next:
	putchar('\n');
}
