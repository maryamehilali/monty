#include "monty.h"

/**
 * tokenize - function that takes a single string and split it into
 *		an array of strings using the delimeter delim.
 * @string: the input string.
 * @delim: the chosen delimeter.
 * Return: An array containing the result strings.
 */

char **tokenize(char *string, char *delim)
{
	char **words = NULL;
	
	words = malloc(sizeof(char *) * 3);
	if (words == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	words[0] = strtok(string, delim);
	words[1] = strtok(NULL, delim);
	words[2] = NULL;
	return (words);
}
