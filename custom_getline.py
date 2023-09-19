#include "main.h"

/**
 * custom_getline - custom implementation of getline
 * @lineptr: pointer to the line buffer
 * @n: pointer to the size of the buffer
 * @stream: file stream to read from
 *
 * Return: the number of characters read, -1 on failure
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = *lineptr;
	size_t pos = 0;
	char c;

	if (initialize_buffer(lineptr, n) == -1)
		return (-1);

	while (1)
	{
		c = fgetc(stream);

		if (c == EOF)
		{
			if (pos == 0)
				return (-1);
			break;
		}

		if (pos >= *n - 1 && resize_buffer(lineptr, n) == -1)
			return (-1);

		line[pos++] = c;

		if (c == '\n')
			break;
	}

	line[pos] = '\0';
	return (pos);
}

/**
 * initialize_buffer - Initialize the line buffer.
 * @lineptr: pointer to the line buffer
 * @n: pointer to the size of the buffer
 *
 * Return: 0 on success, -1 on failure
 */
int initialize_buffer(char **lineptr, size_t *n)
{
	if (*lineptr == NULL || *n == 0)
	{
		*n = CHUNK_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * resize_buffer - Resize the line buffer.
 * @lineptr: pointer to the line buffer
 * @n: pointer to the size of the buffer
 *
 * Return: 0 on success, -1 on failure
 */
int resize_buffer(char **lineptr, size_t *n)
{
	char *new_line;

	*n *= 2;
	new_line = (char *)realloc(*lineptr, *n);

	if (new_line == NULL)
	{
		free(*lineptr);
		*lineptr = NULL;
		return (-1);
	}
	*lineptr = new_line;
	return (0);
}
