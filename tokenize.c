#include "monty.h"

/**
 * tokenize - function that takes a single string and split it into
 *		an array of strings using the delimeter delim.
 * @delim: the chosen delimeter.
 * Return: An array containing the result strings.
 */

char **tokenize(char *delim)
{
	char **words = NULL;

	words = malloc(sizeof(char *) * 3);
	if (words == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(var.buffer), fclose(var.monty_file);
		exit(EXIT_FAILURE);
	}
	words[0] = strtok(var.buffer, delim);
	words[1] = strtok(NULL, delim);
	words[2] = NULL;
	return (words);
}
