#include "monty.h"

/**
 * rotl_stack - rotates the stack to the top; first becomes the last
 *		second become the first
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void rotl_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr, *tmp;
	(void)line_number;

	ptr = *head;

	if (*head && (*head)->next)
	{
		while(ptr->next)
			ptr = ptr->next;
		tmp = *head;
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		ptr->next = tmp;
		tmp->prev = ptr;
		tmp->next = NULL;
	}
}
/**
 * rotr_stack - rotates the stack to the bottom; first becomes second
 *		last becomes the first
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void rotr_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr, *tmp;
	(void)line_number;

	ptr = *head;

	if (*head && (*head)->next)
	{
		while(ptr->next)
			ptr = ptr->next;
		tmp = ptr->prev;
		(*head)->prev = ptr;
		ptr->next = *head;
		ptr->prev = NULL;
		tmp->next = NULL;
		(*head) = ptr;
	}
}
/**
 * stack_len - funct that counts the number of nodes in doubly linked list
 * @h: pointer to the head of the list
 * Return: number of nodes in the list
 */
size_t stack_len(const stack_t *h)
{
	const stack_t *ptr;
	size_t count = 0;

	ptr = h;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
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
