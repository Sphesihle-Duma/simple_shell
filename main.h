#ifndef _MAIN_H
#define _MAIN_H
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
extern char **environ;
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
int _strlen(char *s);
int _putchar(char c);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *read_input(char *command, size_t buff);
void prompt(void);
void search_and_execute(char *command, char *path, char *argv[]);
void execute_command(char *command, char *argv[], char *envp[]);
int _strcmp(char *s1, char *s2);
#endif

