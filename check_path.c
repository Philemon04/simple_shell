#include "header.h"

/**
 * search_path - searches for the PATH to execute commands
 * @environ: Environment variable
 * Return: The path
 */

char **search_path(char **environ)
{
	int p;
	char **entry_path;

	for (p = 0; environ[p] != NULL; p++)
	{
		if (strncmp(environ[p], "PATH=", 5) == 0)
		{
			entry_path = _which(environ[p] + 5);
			break;
		}
	}

	return (entry_path);
}

/**
 * _strdup - duplicates a strings
 * @string: The string to be duplicated
 * Return: the pointer of the concat string
 */
char *_strdup(char *string)
{
	int j, k;
	char *s;

	if (string == NULL)
		return (NULL);

	j = _strlen(str);
	s = malloc((j + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	for (k = 0; k < j; k++)
		s[k] = string[k];

	s[j] = '\0';

	return (s);
}

/**
 * _itoa - integer to ascii value
 * @integer: the integer
 * @base: the base
 * Return: char
 * Reference: https://gist.github.com/narnat/95733cd0ad7bfac0d90697292914c407
 */

char *_itoa(int integer)
{
	int counter = 0;
	int placeh = integer;
	char *ptr;

	if (integer == 0)
	{
		ptr = malloc(2 * sizeof(char));
		if (ptr == NULL)
			return (NULL);

		ptr[0] = '0';
		ptr[1] = '\0';

		return (ptr);
	}

	while (placeh != 0)
	{
		counter++;
		placeg /= 10;
	}

	ptr = malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	ptr[counter] = '\0';

	while (integer != 0)
	{
		counter--;
		ptr[count] = (num % 10) + '0';
		num /= 10;
	}

	return (ptr);
}
