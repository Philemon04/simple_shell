#include "header.h"

/**
 * _putchar - writhes the character to stdout
 * @c: the character passed
 * Return: returns 1 or -1 on failure
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: the pointer to the string
 * Return: void
 */

void _puts(char *str)
{
	int g;

	for (g = 0; str[g] != '\0'; g++)
	{
		_putchar(str[g]);
	}
	_putchar('\n');
}

/**
 * _strlen - checks the length of string
 * @s: length checker
 * Return: the length
 */

int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return ((i + 1));
}

/**
 * str_concat - back a pointer to array
 * @string1: first array
 * @string2: second array
 * Return: returns an array
 */
char *str_concat(char *string1, char *string2)
{
	char *destination;
	unsigned int i;
	unsigned int k;
	unsigned int size;

	if (string1 == NULL)
		string1 = "";

	if (string2 == NULL)
		string2 = "";

	size = (_strlen(string1) + _strlen(string2) + 1);

	destination = (char *) malloc(size * sizeof(char));

	if (destination == 0)
	{
		return (NULL);
	}

	for (i = 0; *(string1 + i) != '\0'; i++)
		*(destination + i) = *(string1 + i);

	for (k = 0; *(string2 + k)  != '\0'; k++)
	{
		*(destination + i) = *(string2 + k);
		i++;
	}
	destination[i] = '\0';
	return (destination);
}

/**
 * _strcmp - compare a set of strings
 * @string1: first string
 * @string2: second string
 * Return: returns the number
 */
int _strcmp(char *string1, char *string2)
{
	char *pointer1 = string1;
	char *pointer2 = string2;

	while (*pointer1 != '\0' && *pointer2 != '\0' && *pointer1 == *pointer2)
	{
		pointer1++;
		pointer2++;
	}
	return (*pointer1 - *pointer2);
}


