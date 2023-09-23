#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define CUSTOM_LOWERCASE 1
#define CUSTOM_UNSIGNED  2
extern char **environ;

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
	unsigned int len;
	struct Env_type *next;
} type_env;

/**
 * struct liststr - singly linked list
 * @number: the number field
 * @text: a string
 * @next: points to the next node
 */
typedef struct liststr
{
        int number;
        char *text;
        struct liststr *next;
} list_t;

/**
 * struct CommandInfo - Structure to hold command-related information
 * @argument: Main command argument
 * @arguments_list: List of command arguments
 * @executable_path: Path to the command's executable
 * @argument_count: Number of arguments in arguments_list
 * @line_counter: Line number in the script or input where the command appears
 * @error_number: Error number associated with the command (if any)
 * @line_count_flag: Flag to indicate if line counting is enabled
 * @file_name: Name of the script or file where the command appears
 * @environment_variables: List of environment variables
 * @command_history: List of previously executed commands
 * @command_aliases: List of command aliases
 * @environment: Array of environment variable
 * @history_count: Count of command history
 */
typedef struct CommandInfo
{
    char *argument;gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
    char **arguments_list;
    char *executable_path;
    int argument_count;
    unsigned int line_counter;
    int error_number;
    int line_count_flag;
    char *file_name;
    list_t *environment_variables;
    list_t *command_history;
    list_t *command_aliases;
} CommandInfoStruct;

/*builtin_commands1.c*/
int cd_command(char **tok);
int exit_and_free(char **tok, type_env *linklist_env, char *buffer);
int alias_command(void);

/*buitin_command2.c*/
int history_command(void);
int setenv_command(char **tok);
int env_command(char **tok, type_env *env);

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
char *get_environs(const char *key);

/*node_plus.c*/
type_env *node_plus(type_env **home, char *str, unsigned int length);

/*string1.c*/
unsigned int count_words(char *str);
int custom_strlen(char *str);
int custom_strlen_const(const char *str);
int _isdigit(int c);
void _print(const char *str);

/*string2.c*/
int custom_strncmp(char *s1, char *s2, unsigned int bytes);
int custom_atoi(char *str);
char *custom_strdup(char *str);
char *custom_strcat(char *dest, char *src);

void copy_function(char *string_af, char *source, unsigned int result);
void set_function(char *string, int input, int num);
void *realloc_function(char *pointer, unsigned int os, unsigned int ns);
char *custom_getline(int stream);
char **convert_function(char *string, char *delimiter);
/*static void signal_function(int signal);*/
char *custom_strtok_r(char *str, char *delimiter, char **sp);
char *custom_strpbrk(char *str, char *num);
unsigned int custom_strspn(char *str, char *ac);
char *custom_strchr(char *str, char ch);

/*additional*/
int displayCommandHistory(CommandInfoStruct *commandInfo);
int unsetCommandAlias(CommandInfoStruct *commandInfo, char *str);
int setCommandAlias(CommandInfoStruct *commandInfo, char *str);
int printCommandAlias(list_t *node);
int myAlias(CommandInfoStruct *commandInfo);
void free_text_list(list_t **head_pointer);
int delete_n_by_index(list_t **head, unsigned int index);
size_t print_text_list(const list_t *n);
list_t *append_list_node(list_t **head, const char *text, int number);
list_t *add_list_node(list_t **head, const char *text, int number);
ssize_t get_node_with_index(list_t *head, list_t *nd);

list_t *node_with(list_t *nd, char *pf, char c);
size_t _prints_lists(const list_t *n);
char **convert_list_to_strings(list_t *head);
size_t l_length(const list_t *n);
char *mem_init(char *st, char ba, unsigned int n);
char *custom_start(const char *h, const char *n);
char *conv_num(long int number, int base, int formatFlags);
char *mem_init(char *st, char ba, unsigned int n);
char *custom_start(const char *h, const char *n);
char *conv_num(long int number, int base, int formatFlags);

#endif /*MAIN_H*/

