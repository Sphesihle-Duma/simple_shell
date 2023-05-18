#include "main.h"
/**
  * _strlen - finds the string length
  *
  * Description: a function that returns the length of a string.
  * @s: a string
  * Return: a length of a string value.
  */
int _strlen(char *s)
{
	int number_of_chars;

	number_of_chars = 0;
	while (*(s + number_of_chars) != '\0')
	{
		number_of_chars++;
	}
	return (number_of_chars);
}
