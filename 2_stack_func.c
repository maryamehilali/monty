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
	{	tmp = (*head)->next, (*head)->prev = tmp;
		(*head)->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = *head;
		tmp->next = *head, tmp->prev = NULL, *head = tmp; }
	else
	{	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(var.buffer), free(var.cmd_op), free_stack(var.head);
		fclose(var.monty_file), exit(EXIT_FAILURE); }
}
/**
 * sum_two_stack - delete the top of the stack
 *		and add its data to the secont top;
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void sum_two_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int data1, data2;

	if (*head && head && stack_len(*head) >= 2)
	{	data1 = (*head)->n, data2 = (*head)->next->n;
		*head = (*head)->next, (*head)->prev = NULL;
		(*head)->n = data1 + data2, free(ptr); }
	else
	{	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(var.buffer), free(var.cmd_op), free_stack(var.head);
		fclose(var.monty_file), exit(EXIT_FAILURE); }
}
/**
 * no_action - function that dont do anything
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void no_action(stack_t **head, unsigned int line_number)
{	(void)head;
	(void)line_number;
}

/**
 * print_char_stack - function that prints the ascii value
 *		of the data at the top element on the stack
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void print_char_stack(stack_t **head, unsigned int line_number)
{
	(void)line_number;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var.buffer), free(var.cmd_op), free_stack(var.head);
		fclose(var.monty_file), exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var.buffer), free(var.cmd_op), free_stack(var.head);
		fclose(var.monty_file), exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * print_string_stack - function that prints a string using the ascii value
 *		of the data at the top element on the stack and stops
 *		if it finds 0 or out of range of ascii
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void print_string_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	(void)line_number;

	if (head == NULL || *head == NULL)
	{
		printf("\n");
		return;
	}
	while (ptr)
	{
		if (!(ptr->n < 1 || ptr->n > 127 || ptr->n == 0))
			printf("%c", ptr->n);
		else
			break;
		ptr = ptr->next;
	}
	printf("\n");
}
