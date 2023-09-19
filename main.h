#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

#define CHUNK_SIZE 256
#define MAX_COMMAND_LEN 100
extern char **environ;

void errormsg(const char *str);
void tokenizeCommand(char *command, char *args[]);
char *executable(char *command, char *env[]);
char *custom_strtok(char *str, const char *delimiters);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
int my_fgetc(FILE *stream);
int resize_buffer(char **lineptr, size_t *n);
int initialize_buffer(char **lineptr, size_t *n);

#endif /* MAIN_H */
