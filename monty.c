#include "monty.h"
G_var var;
/**
 * main - interpreter for Monty ByteCodes files.
 * @argc: number of arguments to the program
 * @argv: arguments given to the program
 * Return: 0 or 1.
 */
int main(int argc, char **argv)
{
	int line_read, char_read;
	size_t bufsize = sizeof(char) * LINE_SIZE;

	var.buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	var.monty_file = fopen(argv[1], "r");
	if (var.monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	char_read = 0;
	line_read = 1;
	while ((char_read = getline(&(var.buffer), &bufsize, var.monty_file)) != -1)
	{
		var.cmd_op = tokenize(" \t\n");
		if (var.cmd_op[0] == NULL)
		{
			line_read++;
			free(var.cmd_op);
			continue;
		}
		execute_op(line_read);
		line_read++;
		free(var.cmd_op);
	}
	free(var.buffer);
	free_stack(var.head);
	fclose(var.monty_file);
	/*free_stack(&head);*/
	return (EXIT_SUCCESS);
}
