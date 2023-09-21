#ifndef MAIN_H
#define MAIN_H

extern char **environ

#define BUFFER_SIZE 1024

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

#endif /*MAIN_H*/

