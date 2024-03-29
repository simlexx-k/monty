#include "monty.h"

/**
 * free_stack - a Function that ...
 * @head: Description of head.
 * Return: Description of the return value.
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

