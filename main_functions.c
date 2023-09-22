#include "main.h"

/**
 * custom_getline - reads line from stdin
 * @stream: file stream
 * Return: pointer
 */
char *custom_getline(int stream)
{
	unsigned int a, marker;
	char *buff;
	static unsigned int bs = BUFFER_SIZE;

	buff = malloc(sizeof(char) * bs);
	if (buff == NULL)
	{
		perror("memory alloction for buffer fail\n");
		return (NULL);
	}
	marker = 0;
	set_function(buff, '\0', bs);
	while ((a = read(stream, buff + marker, bs - marker)) > 0)
	{

		if (a < (bs - marker))
			return (buff);
		bs *= 2;
		realloc_function(buff, bs, bs / 2);
		if (buff == NULL)
		{
			perror("memory allocation fail\n");
			return (NULL);
		}
		marker += a;
	}
	if (a == 0)
		copy_function(buff, "exit", 5);
	return (buff);
}
/**
  * convert_function - creates token
  * @string: input string
  * @delimiter: delimiters
  * Return: Double pointer
  */
char **convert_function(char *string, char *delimiter)
{
	char **tok, *sp, *toknn;
	unsigned int a, b;

	b = count_words(string);
	tok = malloc((b + 1) * sizeof(char *));
	if (!tok)
	{
		perror("memory allocation fail\n");
		return (NULL);
	}
	tok[0] = toknn = custom_strtok_r(string, delimiter, &sp);
	for (a = 1; toknn; a++)
		tok[a] = toknn = custom_strtok_r(NULL, delimiter, &sp);
	return (tok);
}

static unsigned char flag = 0

/**
  * signal_function - handles signals
  * @signal: signal
  */
static void signal_function(int signal)
{
        if (signal == SIGINT && flag == 0)
                _print("\n$: ");
        else if (flag != 0)
                _print("\n");
}

/**
  * main - entry point
  * Return: 0 or -1.
  */
int main(void)
{
	char p_flags, *buff, *commands, *sp, **toknn;
	env_t *linklist_env;
	struct stat _buffer;

	if (signal(SIGINT, signal_function) == SIG_ERR)
		perror("signal error\n");
	if (fstat(STDIN_FILENO, &_buffer) == -1)
		perror("error with fstat\n"), exit(98);
	p_flags = (_buffer.st_mode & S_IFMT) == S_IFCHR ? 0 : 1;
	linklist_env = path_list();
	if (linklist_env == NULL)
		return (-1);
	sp = NULL;
	while (1)
	{
		flag = 0;
		if (p_flags == 0)
			_print("$: ");
		buff = custom_getline(STDIN_FILENO);
		if (!buff)
			break;
		commands = custom_strtok_r(buff, "\n;", &sp);
		while (commands)
		{
			toknn = convert_function(commands, "\t ");
			if (!toknn)
				break;
			if (builtin_checker(toknn[0]))
				builtin_checker(toknn[0])(toknn, linklist_env, commands);
			else
				flag = 1, execute(toknn, linklist_env);
			free(toknn);
			commands = _strtok_r(NULL, "\n;", &sp);
		}
		free(buff);
	}
	return (0);
}
