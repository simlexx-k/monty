#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    ssize_t read;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        if (execute(line, &stack, line_number, file) == -1)
        {
            free(line);
            fclose(file);
            free_stack(stack);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);

    return (0);
}

