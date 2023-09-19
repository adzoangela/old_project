#include "main.h"
/**
 * expand_line - expane line
 * @lineptr: line ptr
 * @n: n
 *
 * Return: Nothing
 */

void expand_line(char **lineptr, size_t *n)
{
	char *line;
	char *new_line;

	*n *= 2;
	line = *lineptr;
	new_line = (char *)realloc(line, *n);
	if (new_line == NULL)
	{
		free(line);
		*lineptr = NULL;
		return;
	}
	*lineptr = new_line;
}

/**
 * custom_getline - cust getline
 * @lineptr: line pointer
 * @n: bytes
 * @stream: input stream
 *
 * Return: no of bytes
 */

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = *lineptr;
	size_t pos = 0;
	char c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = CHUNK_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
		line = *lineptr;
	}
	while (1)
	{
		c = fgetc(stream);
	if (c == EOF)
	{
		if (pos == 0)
		{
			return (-1);
		}
		else
		{
			break;
		}
	}
	if (pos >= *n - 1)
		expand_line(&line, n);
	line[pos++] = c;
	if (c == '\n')
	{
		break;
	}
	}
	line[pos] = '\0';
	return (pos);
}
