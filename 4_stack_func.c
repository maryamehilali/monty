#include "monty.h"

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
