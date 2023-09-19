#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LEN 100
#define CHUNK_SIZE MAX_COMMAND_LEN
extern char **environ;

void errormsg(const char *str);
void tokenizeCommand(char *command, char *args[]);
char *executable(char *command, char *env[]);
char *custom_strtok(char *str, const char *delimiters);
void exit_handle(char *arg, int *status);
void executeCommand(char *arg, char **args, char **env);
void cd_command(char *arg1, char *arg2);
void errormsg2(char *msg);

#endif /* MAIN_H */
