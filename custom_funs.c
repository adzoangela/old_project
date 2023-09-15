#include "main.h"

/**
 * custom_strtok - custom strtok()
 * @str: input string
 * @ delimeters: delimeters
 *
 * Return: tokens
 */

char *custom_strtok(char *str, const char *delimeters)
{
	static char *next_token = NULL;
	char *token;

	if (str != NULL)
		next_token = str;
	else if (next_token == NULL)
		return (NULL);
	/*ignore leading delimeters*/
	next_token += strspn(next_token, delimeters);
	if (*next_token == '\0')
		return (NULL);
	/*get end of current token*/
	token = next_token;
	next_token += strcspn(next_token, delimeters);
	if (*next_token != '\0')
		*next_token++ = '\0';
	return (token);
}
