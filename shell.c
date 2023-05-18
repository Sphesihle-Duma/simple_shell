#include "main.h"
/**
  * prompt - prints prompts
  */
void prompt(void)
{
	_putchar('$');
	_putchar(32);
	fflush(stdout);
}
/**
  * read_input - read a command
  * @buff: buffer size
  * @command: command
  * Return: pointer to the command
  */
char *read_input(char *command, size_t buff)
{
	if (getline(&command, &buff, stdin) == -1)
	{
		if (feof(stdin))
		{
			_putchar('\n');
			free(command);
			exit(EXIT_FAILURE);
		}
		else
		{
			perror("./shell");
			free(command);
			exit(EXIT_FAILURE);
		}

	}
	return (command);
}
/**
  * interactive - interactive mode
  */
void interactive(void)
{
	char *line = NULL;
	char *argv[2];
	size_t buffersize = 0;
	int status;
	pid_t child;

	while (1)
	{
		prompt();
		line = read_input(line, buffersize);
		if (line == NULL || *line == '\n')
			continue;
		line[_strlen(line) - 1] = '\0';
		argv[0] = line;
		argv[1] = NULL;
		child = fork();
		if (child == -1)
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			execve(argv[0], argv, environ);
			perror("./shell");
			free(line);
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
		free(line);
		line = NULL;
		buffersize = 0;
	}
	free(line);
}
/**
  * non_interactive - noninteractive mode
  */
void non_interactive(void)
{

	char *line = NULL;
	char *argv[2];
	size_t buffersize = 0;
	int status;
	pid_t child;

	while (getline(&line, &buffersize, stdin) != -1)
	{
		line[_strlen(line) - 1] = '\0';
		argv[0] = line;
		argv[1] = NULL;
		child = fork();
		if (child == -1)
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			execve(argv[0], argv, environ);
			perror("./shell");
			free(line);
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
		free(line);
		line = NULL;
		buffersize = 0;
	}
	free(line);
}
/**
  * main - main method
  * Return: 0 on Success
  */
int main(void)
{
	if (isatty(STDIN_FILENO))
		interactive();
	else
		non_interactive();
	return (0);
}

