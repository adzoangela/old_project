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
		{"exit", exit_command},
		{"history", history_comand},
		{"setenv", setenv_command},
		{NULL, NULL}
	};

	i = 0;
	while (*builtins[i].function != NULL)
	{
		if (_strncmp(builtins[i].input, command, _strlen(builtins[i].input)) == 0)
			return (builtins[i].functions);
		i++;
	}
	return (NULL);
}
