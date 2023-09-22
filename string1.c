#include "main.h"

/**
 * count_words - counts words given a delimiter
 * @str: string
 *
 * Return: number of words
 */

unsigned int count_words(char *str)
{
	size_t i, count;
	int f; /*flag*/
	char *delimiter = "\n \t";

	for (i = 0, count = 1, f = 0; str[i]; i++)
	{
		if (f == 0 && (str[i] == delimiter[0] || str[i] == delimiter[1]
			|| str[i] == delimiter[2]) && str[i + 1] != delimiter[0]
			&& str[i + 1] != delimiter[1] && str[i + 1] != delimiter[2])
		{
			f = 1;
			count++;
		}
		else
			f = 0;
	}
	return (count);
}

/**
 * custom_strlen - find len of str
 * @str: string
 *
 * Return: str len
 */
int custom_strlen(char *str)
{
	int count;

	for (count = 0; *str; str++, count++)
		;
	return (count);
}

/**
 * custom_strlen_const - custom_strlen for const strings
 * @str: string
 * Return: str len
 */
int custom_strlen_const(const char *str)
{
	int count;

	for (count = 0; str[count] != '\0'; count++)
		;
	return (count);
}

/**
  * _isdigit - check if characters are digits
  * @c: character
  *
  * Return: 1 (Success), 0 (Failure)
  */

int _isdigit(int c)
{
	if (c > '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
  * _print - simple print
  * @str: string
  *
  * Return: 1 (Success), 0 (Failure)
  */

void _print(const char *str)
{
	int length;

	length = custom_strlen_const(str);
	write(STDOUT_FILENO, str, length);
}
