#include "monty.h"

/**
 * push_to_stack - funct that adds an element to the top of the stack
 *		it adds a node at beginning of a doubly linked list.
 * @head: double pointer to the head of the list top of the stack
 * @line_number: line number
 * Return: nothing
 */
void push_to_stack(stack_t **head, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (head == NULL)
		return;
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
/**
 * print_all_stack - function that prints all the elements on the stack
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void print_all_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	if (head == NULL || *head == NULL)
		return;
	ptr = *head;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * free_stack - funct that frees the stack or the doubly linked list
 * @head: pointer to the top of the stack
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *ptr;

	ptr = head;

	while (ptr)
	{
		ptr = ptr->next;
		free(head);
		head = ptr;
	}
}
/**
 * print_first_stack - function that prints all top element on the stack
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void print_first_stack(stack_t **head, unsigned int line_number)
{
	(void)line_number;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * delete_first_stack - delete the top of the stack;
 *		node at index 0 of a doubly linked list
 * @head: pointer to the head of the list
 * @line_number: line number
 * Return: nothing
 */
void delete_first_stack(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	ptr = *head;

	if (*head)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(ptr);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}}
