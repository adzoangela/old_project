/**
  * custom_strcpy - strcpy() custom
  * @dest: destination
  * @source: source string
  *
  * Return: pointer
  */

char *custom_strcpy(char *dest, const char *source)
{
	unsigned int i;

	for (i = 0; source[i] != '\0'; i++)
		dest[i] = source[i];

	dest[i] = '\0';

	return (dest);
}

/**
  * custom_strcmp - custom strcmp()
  * @str1: frist string
  * @str2: second string
  *
  * Return: int
  */

int custom_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
	{
		return (*str1 - *str2);
	}

	return (0);
}
