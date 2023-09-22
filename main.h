#ifndef MAIN_H
#define MAIN_H

extern char **environ

#define BUFFER_SIZE 1024

/**
  * struct commands_builtin - stuct for func ptrs to builtin cmds
  * @input: builtin cmds
  * @function: function
  */

typedef struct commands_builtin
{
	char *input;
	int (*function)();
} builtin_commands;

/**
  * struct Env_type - linklist in path
  * @str: path e.g(/usr/bin)
  * @len: string length
  * @next: next node
  */

typedef struct Env_type
{
	char *str;
	size_t len;
	struct Env_type *next;
} type_env;

/*builtin_commands1.c*/
int cd_command(char **tok);
int exit_and_free(char **tok, env_t *linklist_env, char *buffer);
int alias_command(void);

/*buitin_command2.c*/
int history_command(void);
int setenv_command(char **tok);
int env_command(char **tok, env_t *env);

/*builtin_checker.c*/
int (*builtin_checker(char *command))();

/*environment_var.c*/
type_env *path_list(void);
char *find_command(char *input, type_env *linklist_env);
type_env *build_linklist(void);
int set_environs(const char *key, const char *value, int status);
int unset_environs(const char *key);

/*execute.c*/
void execute(char *av[], type_env *linklist_env);

/*_free*/
void _free(type_env *home);

/*get_environs.c*/
char *get_environs(const char *key)

/*node_plus.c*/
type_env *node_plus(type_env **home, char *str, unsigned int length);

/*string1.c*/
unsigned int count_words(char *str);
int custom_strlen(char *str);
int custom_strlen_const(const char *str);
int _isdigit(int c);
void _print(const char *str);

/*string2.c*/
int custom_strncmp(char *s1, char *s2, size_t bytes);
int custom_atoi(char *str);
char *custom_strdup(char *str);
char *custom_strcat(char *dest, char *src);

void copy_function(char *string_af, char *source, unsigned int result);
void set_function(char *string, int input, int num);
void *realloc_function(char *pointer, unsigned int os, unsigned int ns);
char *custom_getline(int stream);
char **convert_function(char *string, char *delimiter);
static void signal_function(int signal);
char *custom_strtok_r(char *str, char *delimiter, char **sp);
char *custom_strpbrk(char *str, char *num);
unsigned int custom_strspn(char *str, char *ac);
char *custom_strchr(char *str, char ch);

#endif /*MAIN_H*/

