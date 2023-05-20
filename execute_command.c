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
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}
	else
	{
		perror("./shell");
	}
}
