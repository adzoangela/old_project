#include "main.h"

/**
  * get_environs - acquire the env value from corresponding key
  * @key: (str)string to search for
  * Return: value in key:value pair
  */
char *get_environs(const char *key)
{
	int i, j, length;
	char **environs, *temp;

	if (key == NULL)
		return (NULL);
	environs = environ;
	for (i = 0; environs[i]; i++)
	{
		for (length = 0; environs[i][length] != '='; length++)
			;
		length++;

		temp = malloc((length) * sizeof(char));
		if (temp == NULL)
			return (NULL);
		copy_function(temp, environs[i], length - 1);
		temp[length - 1] = '\0';

		if (custom_strncmp(key, temp, custom_strlen(temp)) == 0)
		{
			free(temp);
			temp = NULL;
			for (j = 0; environs[i][j]; j++)
			{
				if (environs[i][j] == '=')
				{
					temp = &environs[i][j + 1];
					break;
				}
			}
			return (temp);
		}

		free(temp);
		temp = NULL;
	}
	return (NULL);
}
