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
	char *token;
	char **words;
	int i = 0;

	words = malloc(sizeof(char *) * MAX_SIZE);
	if (words == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(string, delim);
	while (token)
	{
		words[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	words[i] = NULL;
	return (words);
}
