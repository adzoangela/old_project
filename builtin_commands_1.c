#include "main.h"

/**
  * cd_command - change working dir
  * @tok: arg list
  *
  * Return: 0 (success)
  */
int cd_command(char **tok)
{
	char *tar_dir, *home_dir;
	char pwd[BUFFER_SIZE];

	home_dir = get_environs("HOME");

	if (tok[1])
	{
		if (tok[1][0] == '~' && !tok[1][1])
			tar_dir = home_dir;
		else if (tok[1][0] == '-' && !tok[1][1])
			tar_dir = get_environs("OLDPWD");
		else
			tar_dir = tok[1];
	}
	else
		tar_dir = home_dir;
	if (tar_dir == home_dir)
		chdir(tar_dir);
	else if (access(tar_dir, F_OK | R_OK) == 0)
		chdir(tar_dir);
	else
		_print("directory not found\n");
	/*set new environment*/
	setenv("OLDPWD", get_environs("PWD"), 1);
	setenv("PWD", getcwd(pwd, sizeof(pwd)), 1);

	return (0);
}

/**
  * exit_and_free - reeremaining alloc spaces and exit
  * @linklist_env: Linked lists to free.
  * @buffer: buffers to free
  * @tok: Check for other inputs
  *
  * Return: -1 (Failure)
  */

int exit_and_free(char **tok, type_env *linklist_env, char *buffer)
{
	unsigned char status;
	int i;

	for (i = 0; tok[1] && tok[1][i]; i++)
	{
		if (!_isdigit(tok[1][i]))
		{
			_print("enter numeric argument\n");
			break;
		}
	}
	status = (tok[1] && i >= custom_strlen(tok[1])) ? (custom_atoi(tok[1])) : 0;
	if (linklist_env && buffer && tok)
	{
		_free(linklist_env);
		linklist_env = NULL;
		free(buffer);
		buffer = NULL;
		free(tok);
		tok = NULL;
	}
	exit(status);
	return (-1);
}

/**
  * alias_command - sets aliases
  * prints them out when no options are supplied
  *
  * Return: 0 (Success)

int alias_command(void)
{
	_print("alias: Usage: alias [-p] [name[=value] ... ]\n");
	_print("\tSet or view aliases.\n\tSet with name=value\n");
	_print("\tView list of aliases without arugments or -p\n");

	return (0);
}
*/
