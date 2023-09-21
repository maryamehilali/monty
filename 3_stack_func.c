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
	{	data1 = (*head)->n, data2 = (*head)->next->n;
		*head = (*head)->next, (*head)->prev = NULL;
		(*head)->n = data2 - data1, free(ptr);
	}
	else
	{	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(var.buffer), free(var.cmd_op), free_stack(var.head);
		fclose(var.monty_file), exit(EXIT_FAILURE); }
}
/**
 * div_two_stack - delete the top of the stack
 *		and divides the secont top data by the first;
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void div_two_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int data1, data2;

	if (*head && head && stack_len(*head) >= 2)
	{	data1 = (*head)->n;
		if (data1 == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free(var.buffer), free(var.cmd_op), free_stack(var.head);
			fclose(var.monty_file), exit(EXIT_FAILURE); }
		data2 = (*head)->next->n;
		*head = (*head)->next, (*head)->prev = NULL;
		(*head)->n = data2 / data1, free(ptr);
	}
	else
	{	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(var.buffer), free(var.cmd_op), free_stack(var.head);
		fclose(var.monty_file), exit(EXIT_FAILURE); }
}

/**
 * mul_two_stack - delete the top of the stack
 *		and multiplies its data by the secont top;
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void mul_two_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int data1, data2;

	if (*head && head && stack_len(*head) >= 2)
	{	data1 = (*head)->n, data2 = (*head)->next->n;
		*head = (*head)->next, (*head)->prev = NULL;
		(*head)->n = data2 * data1, free(ptr);
	}
	else
	{	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var.buffer), free(var.cmd_op), free_stack(var.head);
		fclose(var.monty_file), exit(EXIT_FAILURE); }
}
/**
 * mod_two_stack - delete the top of the stack and saves the rest
 *		of the division of data the secont top by the first;
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void mod_two_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int data1, data2;

	if (*head && head && stack_len(*head) >= 2)
	{	data1 = (*head)->n;
		if (data1 == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free(var.buffer), free(var.cmd_op), free_stack(var.head);
			fclose(var.monty_file), exit(EXIT_FAILURE); }
		data2 = (*head)->next->n;
		*head = (*head)->next, (*head)->prev = NULL;
		(*head)->n = data2 % data1, free(ptr);
	}
	else
	{	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(var.buffer), free(var.cmd_op), free_stack(var.head);
		fclose(var.monty_file), exit(EXIT_FAILURE); }
}
