#include "monty.h"

/**
 * addnode - a Function that ...
 * @head: Description of head.
 * @n: Description of n.
 * Return: Description of the return (value.
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head)
    {
        (*head)->prev = new_node;
    }
    *head = new_node;
}
