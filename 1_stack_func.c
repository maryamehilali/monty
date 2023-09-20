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
	
        ptr = *head;
        while (ptr)
        {
                printf("%d\n", ptr->n);
                ptr = ptr->next;
        }
}
/*print_first_stack == print first node
delete_first_stack == delete first node*/