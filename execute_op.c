#include "monty.h"

/**
 * execute_op - function that execute the right function depending
 *		on the giving opcode
 * @cmd_arg: the command and it's arguments taken from the file
 * @line: the line number of the command
 * @head: double pointer to the head of the doubly linked list
 * Return: Void
 */

void execute_op(char **cmd_arg, unsigned int line, stack_t **head)
{
	instruction_t options[] = {
		{"push", push_to_stack},
		{"pall", print_all_stack},
	/**
	 * {"pint", print_first_stack},{"pop", delete_first_stack},
	 * {"swap", swap_two_stack},{"add", sum_two_stack},
	 * {"nop", no_action},
	 */
		{NULL, NULL}
	};
	int i = 0;

	while (options[i].opcode != NULL &&
			(strcmp(options[i].opcode, cmd_arg[0]) != 0))
		i++;
	if (options[i].f == push_to_stack)
	{
		if (cmd_arg[1])
		{
			if (atoi(cmd_arg[1]) != 0 || strcmp(cmd_arg[1], "0") == 0)
				push_to_stack(head, atoi(cmd_arg[1]));
			else
			{
				fprintf(stderr, "L%d: usage: push integer", line);
				exit(EXIT_FAILURE); }}
		else
		{
			fprintf(stderr, "L%d: usage: push integer", line);
			exit(EXIT_FAILURE); }
	}
	else if (options[i].f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s", line, cmd_arg[0]);
		exit(EXIT_FAILURE); }
	else
		options[i].f(head, line);
}
