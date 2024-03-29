#include "monty.h"

void free_stack(stack_t *head) 
{
    stack_t *tmp;

    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

