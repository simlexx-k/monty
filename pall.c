#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number being executed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    /* Print stack values */
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

