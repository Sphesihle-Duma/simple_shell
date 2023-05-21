#include "main.h"
/**
  * _strcmp - compares two strings
  * Description: compares two strings and return an integer less
  * than 0 if string 2 is equal to or -1 if less than or 1 if
  * greater than string 1.
  * @s1: first string
  * @s2: second string
  * Return: 1 or -1 or 0
  */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (i >= 0 && (s1[i] != '\0' && s2[i] != '\0'))
	{
		if (*(s2 + i) == *(s1 + i))
		{
			i++;
		}
		else if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
