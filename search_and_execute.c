#include "main.h"
/**
  * search_and_execute - searches and executes a command
  * @command: command
  * @path: path global variable
  * @argv: array of strings
  */
void search_and_execute(char *command, char *path, char *argv[])
{
	char *dir_token;
	char full_path[128];
	char *dir_temp = _strdup(path);
	char **env = environ;

	if (dir_temp == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	dir_token = strtok(dir_temp, ":");
	while (dir_token != NULL)
	{
		_strcpy(full_path, dir_token);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		argv[0] = full_path;
		if (_strcmp(command, "env") == 0)
		{
			while (*env != NULL)
			{
				printString(*env);
				env++;
			}
			break;
		}
		if (access(argv[0], X_OK) == 0)
			break;
		dir_token = strtok(NULL, ":");
	}
	free(dir_temp);
	if (_strcmp(command, "env") != 0)
		execute_command(argv[0], argv, environ);
}
