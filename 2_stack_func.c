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

	if (head && *head && stack_len(*head) >= 2)
	{
		tmp = (*head)->next;
		(*head)->prev = tmp;
		(*head)->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = *head;
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp; }
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE); }}
/**
 * sum_two_stack - delete the top of the stack
 *		and add its data to the secont top;
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void sum_two_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;
	int data1, data2;

	ptr = *head;

	if (*head && head && stack_len(*head) >= 2)
	{
		data1 = (*head)->n, data2 = (*head)->next->n;
		*head = (*head)->next, (*head)->prev = NULL;
		(*head)->n = data1 + data2, free(ptr); }
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE); }}

