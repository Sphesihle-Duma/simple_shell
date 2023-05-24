#include "main.h"
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
	int status;

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[argc] = NULL;
	if (argc > 0 && _strcmp(argv[0], "exit") == 0)
	{
		if (argc > 1)
		{
			status = _atoi(argv[1]);
			if (status < 0 || status > 255)
				perror(argv[1]);
			free(line);
			exit(status);
		}
		else
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
	}
}

/**
 * interactive - interactive mode
 */
void interactive(void)
{
	char *line = NULL;
	char *argv[128];
	size_t buffersize = 0;

	while (1)
	{
		prompt();
		line = read_input(line, buffersize);
		if (line == NULL || *line == '\n')
			continue;
		line[_strlen(line) - 1] = '\0';
		parse_arguments(line, argv);
		if (_strchr(argv[0], '/') != NULL)
		{
			execute_command(argv[0], argv, environ);
		}
		else
			search_and_execute(argv[0], getenv("PATH"), argv);
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

	while (getline(&line, &buffersize, stdin) != -1)
	{
		line[_strlen(line) - 1] = '\0';
		parse_arguments(line, argv);
		if (_strchr(argv[0], '/') != NULL)
			execute_command(argv[0], argv, environ);
		else
			search_and_execute(argv[0], getenv("PATH"), argv);

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

