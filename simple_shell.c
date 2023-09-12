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
			args[0] = command;
			args[1] = NULL;
			env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin";
			env[1] = NULL;
			if (execve(command, args, env) == -1)
				errormsg("./shell: ");
		}
		else
			wait(&status);
	}
	free(command);
	return (0);
}
