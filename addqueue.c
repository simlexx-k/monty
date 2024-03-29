#include "monty.h"

void addqueue(stack_t **head, int n) 
{
    stack_t *new_node = malloc(sizeof(stack_t));
    stack_t *last;

    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->n = n;
    new_node->next = NULL;

    if (!*head) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    last = *head;
    while (last->next) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

