#include <stdio.h>
#include "monty.h"

/**
 * execute - Execute a line of Monty bytecode
 * @content: Line of Monty bytecode
 * @head: Pointer to the top of the stack
 * @counter: Line number being executed
 * @file: Pointer to the Monty file being executed
 *
 * Return: 1 if successful, 0 otherwise
 */

int execute(char *content, stack_t **head, unsigned int counter, FILE *file)
{
	instruction_t instructions[] = {
		{"push", f_push},
		{"pall", f_pall},
		/* Add more opcodes here as needed */
		{NULL, NULL}
	};
	char *opcode, *arg;
	int i;

	opcode = strtok(content, " \n");
	if (!opcode || opcode[0] == '#')
		return (1);

	arg = strtok(NULL, " \n");
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (!arg && strcmp(opcode, "push") == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", counter);
				fclose(file);
				/**
				 * free_stack - a Function that ...
				 * @head: Description of head.
				 * Return: Description of the return value.
				 */
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
			instructions[i].f(head, arg ? atoi(arg) : 0);
			return (1);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
	fclose(file);
	free_stack(*head);
	exit(EXIT_FAILURE);
}

