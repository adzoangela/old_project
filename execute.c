#include "main.h"

/**
  * execute - executes input command
  * @av: arr of tok
  * @linklist_env: PATH in LL form
  *
  * Return: 0 (Success), -1 (failure)
  */
void execute(char *av[], type_env *linklist_env)
{
	pid_t child_pid = 0;
	char *absolute_path;

	absolute_path = find_command(av[0], linklist_env);
	if (absolute_path NULL)
	{
		perror("command not found\n");
		return;
	}

	child_pid = fork()
	if (child_pid == -1)
	{
		perror("fork() failed\n");
		break;
	}
	else if (child_pid == 0)
	{
		if (execve(absolute_path, av, environ) == -1)
			perror("execve() failed\n");
		break;
	}
	else
	{
		free(absolute_path);
		if (wait(NULL) == -1)
			perror("wait failed\n");
		break;
	}
}
