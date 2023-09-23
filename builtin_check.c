#include "main.h"

/**
  * builtin_checker - checks if the command is a builtin command
  * @command: command
  *
  * Return: ptr to func
*/
int (*builtin_checker(char *command))()
{
	unsigned int i;
	builtin_commands builtins[] = {
		{"alias", alias_command},
		{"cd", cd_command},
		{"env", env_command},
		{"exit", exit_and_free},
		{"history", history_command},
		{"setenv", setenv_command},
		{"alias", alias_command},
		{NULL, NULL}
	};

	i = 0;
	while (*builtins[i].function != NULL)
	{
		if (custom_strncmp(builtins[i].input, command,
			custom_strlen(builtins[i].input)) == 0)
			return (builtins[i].function);
		i++;
	}
	return (NULL);
}
