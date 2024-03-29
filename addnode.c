
#include "monty.h"

void addnode(stack_t **head, int n) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

