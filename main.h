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
char *_strcat(char *dest, char *src);
#endif

