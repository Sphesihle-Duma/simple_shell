#include "main.h"

/**
 * _strncmp - compares only the first (at most) n bytes of s1 and s2
 * @s1 - first string
 * @s2 - second string
 * @n - the maximum number of bytes to compare
 * Return: 1 or -1 or 0
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{

	int i = 0;

	while (i < n && (s1[i] != '\0' && s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
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
		i++;
	}
	if (i == n)
		return (0);

	return (s1[i] - s2[i]);
}
