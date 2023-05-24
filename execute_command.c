#include "main.h"
/**
  * execute_command - execute command
  * @command: command
  * @argv: array of strings
  * @envp: array of environment variables
  */
void execute_command(char *command, char *argv[], char *envp[])
{
	pid_t child;
	int status;
	char error_msg[100];

	if (access(command, X_OK) == 0)
	{
		child = fork();
		if (child == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			execve(command, argv, envp);
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}
	else
	{
		strcpy(error_msg, command);
		strcat(error_msg, ": ");
		strcat(error_msg, "1: ");
		strcat(error_msg, "Not found");
		printString(error_msg);
	}
}
