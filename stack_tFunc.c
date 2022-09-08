#include "monty.h"
/**
 *
 */
int CountStack(stack_t **head)
{
	stack_t *dir = *head;
	int count = 0;

	if (!head || !*head)
		return (count);
	while (dir)
	{
		count++;
		dir = dir->next;
	}
	return (count);
}
/**
 *
 *
 *
 */
void free_stack(stack_t **head)
{
	stack_t *temp = *head;

	while (*head)
	{
		*head = (*head)->next;
		free(temp);
		temp = *head;
	}
}
/**
 *
 *
 *
 */
int _isascii(int c)
{
	(void)c;
	return (0);
}
