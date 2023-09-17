#include "main.h"

/**
 * custom_strtok - custom strtok()
 * @str: input string
 * @delimeters: delimeters
 *
 * Return: tokens
 */

char *custom_strtok(char *str, const char *delimeters)
{
	static char *next_token;
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

/**
 * tokenizeCommand - tokenize command
 * @command: command to tokenize
 * @args: tokenized commands
 *
 * Return: Nothing
 */

void tokenizeCommand(char *command, char *args[])
{
	char *tok;
	int count_arg = 0;

	tok = strtok(command, " ");
	while (tok != NULL && count_arg < MAX_COMMAND_LEN - 1)
	{
		args[count_arg] = tok;
		tok = strtok(NULL, " ");
		count_arg++;
	}
	args[count_arg] = NULL;
}

/**
 * executable - find executable file
 * @command: command
 * @env: env var path
 *
 * Return: executable
 */

char *executable(char *command, char *env[])
{
	char *path = getenv("PATH");
	char *dir[MAX_COMMAND_LEN];
	char *exe = malloc(MAX_COMMAND_LEN * sizeof(char));
	int i, count_dir;
	char *tok;

	(void)env;

	if (path == NULL || exe == NULL)
		errormsg("./shell: ");
	tok = custom_strtok(path, ":");
	count_dir = 0;

	while (tok != NULL && count_dir < MAX_COMMAND_LEN - 1)
	{
		dir[count_dir] = tok;
		tok = custom_strtok(NULL, ":");
		count_dir++;
	}
	dir[count_dir] = NULL;

	for (i = 0; i < count_dir; i++)
	{
		snprintf(exe, MAX_COMMAND_LEN, "%s/%s", dir[i], command);
		if (access(exe, X_OK) != -1)
			return (exe);
	}
	free(exe);
	return (NULL);
}
