#include "main.h"

/**
 * _strcat - joins two strings together.
 * @src - the source string to copy from.
 * @dest - the destination string to join to.
 *
 * Return: a pointer to the resulting string destination.
 */

char* _strcat(char* dest, char* src)
{
	char* p = dest;

	for (; *dest; dest++)
		;

	for (; *src; dest++, src++)
		*dest = *src;

	*p = '\0';
	return (dest);
}
