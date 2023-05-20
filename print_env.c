#include "main.h"



void print_currentenv()
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
