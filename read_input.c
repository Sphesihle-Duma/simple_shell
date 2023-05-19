#include "main.h"
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
