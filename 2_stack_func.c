#include "monty.h"
/**
 * swap_two_stack - swap the first two elements on the top of the stack;
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void swap_two_stack(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (*head && (*head)->next)
	{
		tmp = (*head)->next;
		(*head)->prev = tmp;
		(*head)->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = *head;
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}}
/**
 * is_integer - function that verifies if a string is an int
 * @arg: the string
 * Return: 1 if an integer, 0 otherwise
 */
int is_integer(char *arg)
{
	if (arg == NULL || *arg == '\0')
		return (0);
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (isdigit(*arg) == 0)
			return (0);
		arg++;
	}
	return (1);
}
