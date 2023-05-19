#include "main.h"

/**
 * _strdup - duplicates a string.
 * @str: the string to be duplicated.
 *
 * Return: a pointer to the newly allocated space in memory
 */

char *_strdup(char *str)
{
	int i, len = 0;
	char *dup_str;

	while (str[len] != '\0')
	{
		len++;
	}
	dup_str = malloc(sizeof(char) * (len + 1));
	if (dup_str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		dup_str[i] = s[i];
	}
	dup_str[len] = '\0';
	return (dup_str);
}
