#include "main.h"

/**
 * handle_builtin_commands - Handle built-in commands
 * @argc: Number of arguments
 * @argv: Array of arguments
 */
void handle_builtin_commands(int argc, char *argv[])
{
	if (argc > 2 && _strcmp(argv[0], "setenv") == 0)
	{
		if (set_environment_variable(argv[1], argv[2]) == -1)
			perror("setenv");
	}
	else if (argc > 1 && _strcmp(argv[0], "unsetenv") == 0)
	{
		if (unset_environment_variable(argv[1]) == -1)
			perror("unsetenv");
	}
}

