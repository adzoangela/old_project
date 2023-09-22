#include "main.h"

/**
  * path_list - builds a linked list from PATH
  *
  * Return: pointer to linked list
  */

type_env *path_list(void)
{
	unsigned int length = 0,/* m = 0,*/ n = 0;
	char *environs;
	char buffer[BUFFER_SIZE];
	type_env *home = NULL;

	environs = get_environs("PATH");

	while (*environs)
	{
		buffer[n++] = *environs;
		length++;
		if (*environs == ':')
		{
			length--;
			buffer[n - 1] = '/';
			buffer[n] = '\0';
			node_plus(&home, buffer, length);
			length = 0;
			n = 0;
		}
		environs++;
	}
	return (home);
}

/**
  * find_command - search system to find a command
  * @input: command
  * @linklist_env: search path
  *
  * Return: absolute path (success) , NULL (failure)
  */
char *find_command(char *input, type_env *linklist_env)
{
	char *absolute_path;
	type_env *current_path;
	int stat;

	current_path = linklist_env;
	if (current_path == NULL || input == NULL)
		return (NULL);

	if ((custom_strncmp(input, "/", 1) == 0
			|| custom_strncmp(input, "./", 2) == 0)
			&& access(input, F_OK | X_OK) == 0)
	{
		absolute_path = custom_strdup(input);
		return (absolute_path);
	}
	while (current_path != NULL)
	{
		absolute_path = custom_strdup(current_path->str);
		if (absolute_path == NULL)
			return (NULL);

		absolute_path = custom_strcat(absolute_path, input);
		if (absolute_path == NULL)
			return (NULL);
		/* check if current_path exits in dir*/
		stat = access(absolute_path, F_OK | X_OK);
		if (stat == 0)
			return (absolute_path);

		free(absolute_path);
		current_path = current_path->next;
	}
	return (NULL);
}

/**
  * build_linklist - builds a linlist from path
  *
  * Return: ptr to linklist
  */
type_env *build_linklist(void)
{
	int i = 0;/*j = 0;*/
	char **environs;
	type_env *current_path = NULL;

	environs = environ;
	while (environs[i])
	{
		node_plus(&current_path, environs[i], custom_strlen(environs[i]));
		i++;
	}
	return (current_path);
}

/**
  * set_environs - sets env.
  * @key: key in key=value
  * @value: value in key=value
  * @status: flag to overwrite or maintain
  *
  * Return: 0 (success), -1 (failure)
  */
int set_environs(const char *key, const char *value, int status)
{
	return (setenv(key, value, status));
}

/**
  * unset_environs - unset env variable.
  * @key: key inkey=value pair to unset
  *
  * Return: Success or failure
  */
int unset_environs(const char *key)
{
	return (unsetenv(key));
}
