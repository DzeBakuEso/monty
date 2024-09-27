#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Function Prototypes */
void execute_file(FILE *file);
int execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);


/* Main function */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_file(file);
	fclose(file);
	return (EXIT_SUCCESS);
}


/* Function to execute commands from the file */
void execute_file(FILE *file)
{
	char *opcode;
	stack_t *stack = NULL;
	char line[1024];
	unsigned int line_number = 1;

	while (fgets(line, sizeof(line), file)) /* Read each line */
	{
		opcode = strtok(line, " \n"); /* Tokenize line for opcodes */
		if (opcode)
		{
			if (execute_opcode(opcode, &stack, line_number) != 0)
			{
				free_stack(stack); /* Free stack on error */
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	free_stack(stack); /* Free stack after execution */
}


/* Function to execute a specific opcode */
int execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		char *value = strtok(NULL, " \n");

		if (value)

		{
			stack_t *new_node = malloc(sizeof(stack_t));

			if (!new_node)
			{
				fprintf(stderr, "Error: malloc failed\n");
				return (-1);
			}
			new_node->n = atoi(value);
			new_node->next = *stack;
			new_node->prev = NULL;

			if (*stack)
				(*stack)->prev = new_node;

			*stack = new_node;
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (-1);
		}
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		stack_t *current = *stack;

		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
/* Add other opcodes handling here... */
	return (0); /* Indicate success */
}


/* Function to free the stack */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
