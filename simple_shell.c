#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LEN 100
/*extern char **environ;*/

/**
 * errormsg - print error message
 * @str: message
 *
 * Return: Nothing
 */

void errormsg(const char *str)
{
	perror(str);
	exit(1);
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
	tok = strtok(path, ":");
	count_dir = 0;

	while (tok != NULL && count_dir < MAX_COMMAND_LEN - 1)
	{
		dir[count_dir] = tok;
		tok = strtok(NULL, ":");
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

/**
 * main - Simple shell
 *
 * Return: 0 (Success)
 */

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t command_length;
	int status;
	pid_t child_pid;
	char *exe;
	char *args[MAX_COMMAND_LEN];
	char *env[1024];

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		command_length = getline(&command, &command_size, stdin);
		if (command_length == -1)
			errormsg("./shell: ");
		command[strcspn(command, "\n")] = '\0';
		child_pid = fork();
		if (child_pid == -1)
			errormsg("./shell: ");
		else if (child_pid == 0)
		{
			tokenizeCommand(command, args);
			env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin";
			env[1] = NULL;
			exe = executable(args[0], env);
			if (exe == NULL)
				errormsg("./shell: ");
			if (execve(exe, args, env) == -1)
				errormsg("./shell: ");
		}
		else
			wait(&status);
	}
	free(command);
	return (0);
}
