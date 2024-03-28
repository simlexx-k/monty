#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number being executed.
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    int value;

    /* Check if argument is missing */
    if (!token || !isdigit(token[0]))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert token to integer */
    value = atoi(token);

    /* Create new node */
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update previous top node, if any */
    if (*stack)
        (*stack)->prev = new_node;

    /* Update stack pointer */
    *stack = new_node;
}

