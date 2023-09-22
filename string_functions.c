#include "main.h"

/**
 * custom_strchr - finds a char
 * @str: string
 * @ch: char
 * Return: pointer
 */
char *custom_strchr(char *str, char ch)
{
	int length, a;

	length = custom_strlen(str);
	for (a = 0; a < length; a++)
	{
		if (*(str + a) == ch)
			return (str + a);
	}
	str = '\0';
	return (str);
}
/**
 * custom_strspn - gets length
 * @str: string
 * @ac: string
 * Return: bytes
 */
unsigned int custom_strspn(char *str, char *ac)
{
	int string_length, a, ind;

	string_length = custom_strlen(str);
	a = 0;
	ind = 0;
	while (a < string_length)
	{
		if (custom_strchr(ac, *(str + a)))
			ind++, a++;
		else
			return (ind);
	}
	return (ind);
}

/**
 * custom_strpbrk - search string for bytes
 * @str: string
 * @num: bytes
 * Return: pointer
 */
char *custom_strpbrk(char *str, char *num)
{
	char *t;

	t = num;
	for (; *str != '\0'; str++)
	{
		while (*num != '\0')
		{
			if (*str == *num)
				return (str);
			num++;
		}
		num = t;
	}
	if (*str == '\0')
		return (0);

	return (str);
}

/**
 * custom_strtok_r - tokenizer
 * @str: string
 * @delimiter: delimiter
 * @sp: saves index
 * Return: pointer
 */
char *custom_strtok_r(char *str, char *delimiter, char **sp)
{
	char *toknn;

	if (str == NULL)
	{
		if (*sp == NULL)
			return (NULL);
		str = *sp;
	}
	str += custom_strspn(str, delimiter);
	if (*str == '\0')
	{
		*sp = NULL;
		return (NULL);
	}
	toknn = str;
	str = custom_strpbrk(toknn, delimiter);
	if (str == NULL)
		*sp = NULL;
	else
	{
		*str = '\0';
		*sp = str + 1;
	}
	return (toknn);
}
