#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number being executed.
 */

/**
 * f_pall - a Function that ...
 * @head: Description of head.
 * @counter: Description of counter.
 * Return: Description of the return value.
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

