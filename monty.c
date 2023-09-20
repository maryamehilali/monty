#include "monty.h"

int main(int argc, char **argv)
{
	FILE *monty_file;
	int line_read, char_read;
	char *buffer;
	size_t bufsize = sizeof(char) * LINE_SIZE;
	char **cmd_op;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	char_read = 0;
	line_read = 1;
	while ((char_read = getline(&buffer, &bufsize, monty_file)) != -1)
	{
		printf("line %d: %s", line_read, buffer);
		cmd_op = tokenize(buffer, " 	\t\n");
		if (cmd_op[0] == NULL)
		{
			line_read++;
			continue;
		}
		execute_op(cmd_op, line_read, &head);
		line_read++;
	}
	fclose(monty_file);
	/*free_stack(&head);*/
	return (EXIT_SUCCESS);
}
