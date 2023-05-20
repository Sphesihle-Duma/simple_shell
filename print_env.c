#include "main.h"

/**
 * print_currentenv - prints the current environment.
 *
 * Return: Nothing
 */

void print_currentenv()
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
