#include "main.h"

alias_struct *node = NULL;
/**
  * alias_function - handling alias
  * @tok: tokens
  *
  * Return: 0 (Success), -1 (Failure)
  */

int alias_command(char **tok)
{	
	alias_struct *tmp = node;
	int i, count = 0;
	char *value;

	if (!tok[0])
	{
		while (tmp)
		{
			alias_print_func(tmp);
			tmp = tmp->next;
		}
		return (count);
	}
	for (i = 0; tok[i]; i++)
	{
		tmp = node;
		value = custom_strchr(tok[i], '=');
		if (value == NULL)
		{
			while (tmp)
			{
				if (custom_strcmp(tok[i], tmp->name) == 0)
				{
					alias_print_func(tmp);
					break;
				}
				tmp = tmp->next;
			}
			if (tmp == NULL)
				return (-1);
		}
		else
			alias_build(tok[i], value);
	}
	return (count);
}

/**
  * alias_print_func - print output for alias_function
  * @alias: input alias
  *
  * Return: NOthing
  */

void alias_print_func(alias_struct *alias)
{
	char *input_alias;
	int length = custom_strlen(alias->name) + custom_strlen(alias->value) + 4;

	input_alias = malloc(sizeof(char) * (length + 1));
	if (input_alias == NULL)
		return;

	custom_strcpy(input_alias, alias->name);

	custom_strcat(input_alias, "='");

	custom_strcat(input_alias, alias->value);

	custom_strcat(input_alias, "'\n");

	write(STDOUT_FILENO, input_alias, length);

	free(input_alias);
}

/**
  * alias_build - create additional alias set
  * @name: name
  * @var: value
  *
  * Return: Nothing
  */

void alias_build(char *name, char *var)
{
	alias_struct *tmp = node;
	int length, j, k;
	char *update_var;

	*var = '\0';
	var++;
	length = custom_strlen(var) - custom_strspn(var, "'\"");
	update_var = malloc(sizeof(char) * (length + 1));
	if (update_var == NULL)
		return;
	for (j = 0, k = 0; var[j]; j++)
	{
		if (var[j] != '\'' && var[j] != '"')
			update_var[k++] = var[j];
	}
	update_var[k] = '\0';
	while (tmp)
	{
		if (custom_strcmp(name, tmp->name) == 0)
		{
			free(tmp->value);
			tmp->value = update_var;
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		node_plus_alias(&node, var, update_var);
}
