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
* @line: the pointer to the string
* Return: void
*/

void _puts(char *line)
{
	int j;

	for (j = 0 ; line[j] != '\0' ; j++)
	{
		_putchar(line[j]);
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
	int j;

	j = 0;
	while (s[j] != '\0')
	{
		j++;
	}
	return ((j + 1));
}

/**
* str_concat - back a pointer to array
* @str1: first array
* @str2: second array
* Return: returns an array
*/
char *str_concat(char *str1, char *str2)
{
	char *end;
	unsigned int i, j, size;

	/*If the array is empty*/
	if (str1 == NULL)
		str1 = "";

	if (str2 == NULL)
		str2 = "";

	/*count size total*/
	size = (_strlen(str1) + _strlen(str2) + 1);

	/*malloc*/
	end = (char *) malloc(size * sizeof(char));

	if (end == 0)
	{
		return (NULL);
	}

	/*Concatenate arrays*/
	for (i = 0; *(str1 + i) != '\0'; i++)
		*(end + i) = *(str1 + i);

	for (j = 0; *(str2 + j) != '\0'; j++)
	{
		*(end + i) = *(str2 + j);
		i++;
	}
	end[i] = '\0';

	return (end);
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
