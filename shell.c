#include "main.h"
/**
 * prompt - prints prompt
 */
void prompt(void)
{
	_putchar('$');
	_putchar(' ');
	fflush(stdout);
}

/**
 * parse_arguments - parse command line into arguments
 * @line: input command line
 * @argv: array to store arguments
 * Return: nothing
 */
void parse_arguments(char *line, char *argv[])
{
	char *token;
	int argc = 0;

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[argc] = NULL;
}

/**
 * interactive - interactive mode
 */
void interactive(void)
{
	char *line = NULL;
	char *argv[128];
	size_t buffersize = 0;
	int status;
	pid_t child;

	while (1)
	{
		prompt();
		line = read_input(line, buffersize);
		if (line == NULL || *line == '\n')
			continue;

		line[strlen(line) - 1] = '\0';
		parse_arguments(line, argv);

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
	char *argv[128];
	size_t buffersize = 0;
	int status;
	pid_t child;

	while (getline(&line, &buffersize, stdin) != -1)
	{
		line[strlen(line) - 1] = '\0';
		parse_arguments(line, argv);

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

