#include "main.h"

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
 * exit_handle - handle exit status
 * @arg: arg
 * @status: status
 *
 * Return: Nothing
 */

void exit_handle(char *arg, int *status)
{
	if (arg != NULL)
		*status = atoi(arg);
	else
		*status = 0;
}

/**
 * executeCommand - handle command execution within child process
 * @args: arg
 * @env: env
 * @exe: exe function
 *
 * Return: Nothing
 */

void executeCommand(char *exe, char **args, char **env)
{
	if (exe == NULL)
		errormsg("./shell: ");
	if (execve(exe, args, env) == -1)
		errormsg("./shell: ");
}

/**
 * main - Entry
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
	char **env;
	const char *home_dir;
	char cwd[1024];
	const char *prev_dir;
/*	char *work_dir;
	char dir_path[1024];
*/
	env = environ;
	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		command_length = getline(&command, &command_size, stdin);
		if (command_length == -1)
			errormsg("./shell: ");
		command[strcspn(command, "\n")] = '\0';
		tokenizeCommand(command, args);
		if (strcmp(command, "exit") == 0)
		{
			exit_handle(args[1], &status);
			exit(status);
		}
		if (strcmp(args[0], "cd") == 0)
		{
			if (args[1] == NULL)
			{
				home_dir = getenv("HOME");
				if (home_dir == NULL)
				{
					errormsg("./shell: ");
					continue;
				}
				if (chdir(home_dir) == -1)
				{
					errormsg("./shell: ");
					continue;
				}
			}
			else if (strcmp(args[1], "-") == 0)
			{
				prev_dir = getenv("OLDPWD");
				if (prev_dir == NULL)
				{
					perror("./shell: ");
					continue;
				}
				if (chdir(prev_dir) == -1)
				{
					perror("./shell: ");
					continue;
				}
			}
			else
			{
				if (access(args[1], F_OK) == -1)
				{
					perror("./shell: ");
					continue;
				}
				if (chdir(args[1]) == -1)
				{
					perror("./shell: ");
					continue;
				}
			}
			if (getcwd(cwd, sizeof(cwd)) == NULL)
			{
				errormsg("./shell: ");
				continue;
			}
			if (setenv("OLDPWD", getenv("PWD"), 1) == -1)
			{
				errormsg("./shell: ");
				continue;
			}
			if (setenv("PWD", cwd, 1) == -1)
			{
				perror("./shell: ");
				continue;
			}
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
			errormsg("./shell: ");
		else if (child_pid == 0)
		{
			exe = executable(args[0], env);
			executeCommand(exe, args, env);
		}
		else
			wait(&status);
	}
	free(command);
	return (0);
}
