#include "main.h"

/**
  * history_command - prints history
  *  also clears history with commnand '-c'
  *
  * Return: 0 (Success), 1 (Failure)
  */

int history_command(void)
{
	_print("history: usage: history [-c]\n");
	_print("\tView history\n ");
	_print("\t'history -c' to clear\n");
	return (0);
}

/**
  * setenv_command - sets environmental variables
  * according to user specifications
  * @tok: key-value pair
  *
  * Return: 0 (Success), -1 (Failure)
  */

int setenv_command(char **tok)
{
	char *k, *v, *save_ptr;
	int stat, i, j;

	for (i = 0, j = 1; tok[1][i]; i++)
		if (tok[1][i] == '=')
			j++;
	for (i = 0; tok[i]; i++)
		;
	if (!tok[1] || i == 0 || j != 2)
	{
		_print("setenv: Usage: setenv KEY=VALUE\n");
		return (-1);
	}

	k = custom_strtok_r(tok[1], "=", &save_ptr);

	v = custom_strtok_r(NULL, "=", &save_ptr);

	stat = set_environs(k, v, 0);
	if (stat == 0)
		return (stat);

	return (-1);
}

/**
  * env_command - prints current env
  * @tok: tokens
  * @env: linklist env
  *
  * Return: 0 (Success), -1 (Failure)
  */

int env_command(char **tok, type_env *env)
{
	char **environs;

	if (tok[1])
		_print("Usage: env\n");

	environs = environ;

	if (!environs || !environ)
		return (-1);

	for ( ; *environs; environs++)
	{
		write(STDOUT_FILENO, *environs, custom_strlen(*environs));
		write(STDOUT_FILENO, "\n", 1);
	}
	env++;

	return (0);
}
