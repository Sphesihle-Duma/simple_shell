#include "main.h"
/**
 * set_environment_variable - Set or modify an environment variable
 * @name: Name of the environment variable
 * @value: Value to assign to the environment variable
 * Return: 0 on success, -1 on failure
 */
int set_environment_variable(const char *name, const char *value)
{
	if (name == NULL || value == NULL)
	{
		perror("setenv");
		return (-1);
	}
	if (setenv(name, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}
