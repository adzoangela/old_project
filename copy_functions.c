#include "main.h"

/**
 * realloc_function - reallocates memory
 * @pointer: pointer
 * @os: old size
 * @ns: new size
 * Return: address
 */
void *realloc_function(char *pointer, unsigned int os, unsigned int ns)
{
	char *temp, *buffer;
	unsigned int a;

	if (pointer == NULL)
	{
		buffer = malloc(ns);
		if (buffer == NULL)
			return (NULL);
		return (buffer);
	}
	if (ns == os)
		return (pointer);
	if (ns == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}
	if (ns > os)
	{
		buffer = malloc(ns * sizeof(char));
		temp = pointer;

		set_function(buffer, '\0', ns);
		for (a = 0; a < os; a++)
			buffer[a] = temp[a];
		free(pointer);
		return (buffer);
	}
	return (pointer);
}
/**
 * set_function - fill string
 * @string: string
 * @input: char
 * @num: number of chars
 */
void set_function(char *string, int input, int num)
{
	int a;

	for (a = 0; a < num; a++)
		string[a] = input;
}

/**
 * copy_function - copies string
 * @string_af: string result
 * @source: source
 * @result: bytes
 */
void copy_function(char *string_af, char *source, unsigned int result)
{
	unsigned int a;

	for (a = 0; a < result; a++)
		string_af[a] = source[a];
}
