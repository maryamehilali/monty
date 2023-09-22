#include "monty.h"

/**
 * execute_op - function that execute the right function depending
 *		on the giving opcode
 * @line: the line number of the command
 * Return: Void
 */

void execute_op(unsigned int line)
{
	instruction_t options[] = {
		{"push", push_to_stack},
		{"pall", print_all_stack},
		{"pint", print_first_stack},
		{"pop", delete_first_stack},
		{"swap", swap_two_stack},
		{"add", sum_two_stack},
		{"nop", no_action},
		{"sub", sub_two_stack},
		{"div", div_two_stack},
		{"mul", mul_two_stack},
		{"mod", mod_two_stack},
		{"pchar", print_char_stack},
		{NULL, NULL}
	};
	int i = 0;

	while (options[i].opcode != NULL &&
			(strcmp(options[i].opcode, var.cmd_op[0]) != 0))
		i++;
	if (options[i].f == push_to_stack)
	{
		if (var.cmd_op[1] && is_integer(var.cmd_op[1]))
			push_to_stack(&(var.head), atoi(var.cmd_op[1]));
		else
		{	fprintf(stderr, "L%d: usage: push integer\n", line);
			free(var.cmd_op), free(var.buffer);
			free_stack(var.head), fclose(var.monty_file);
			exit(EXIT_FAILURE); }
	}
	else if (options[i].f == NULL)
	{	fprintf(stderr, "L%d: unknown instruction %s\n", line, var.cmd_op[0]);
		free(var.cmd_op), free(var.buffer);
		free_stack(var.head), fclose(var.monty_file);
		exit(EXIT_FAILURE);
	}
	else
		options[i].f(&(var.head), line);
}
