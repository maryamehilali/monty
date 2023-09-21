#include "monty.h"
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
