#include "monty.h"
/**
 * sub_two_stack - delete the top of the stack
 *		and substracts add its data from the secont top;
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void sub_two_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;
	int data1, data2;

	ptr = *head;

	if (*head && head && stack_len(*head) >= 2)
	{
		data1 = (*head)->n, data2 = (*head)->next->n;
		*head = (*head)->next, (*head)->prev = NULL;
		(*head)->n = data2 + data1, free(ptr);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE); }}

