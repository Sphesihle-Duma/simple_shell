#include "main.h"
/**
 * unset_environment_variable - Unset an environment variable
 * @name: Name of the environment variable to unset
 * Return: 0 on success, -1 on failure
 */
int unset_environment_variable(const char *name)
{
	if (name == NULL)
	{
		perror("unsetenv");
		return (-1);
	}
	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}

