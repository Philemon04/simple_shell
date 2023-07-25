#include "header.h"

/**
 * search_path - searches for the PATH to execute commands
 * @environ: Environment variable
 * Return: The path
 **/

char **search_path(char **environ)
{
	int place = 0;
	char **path_of_token;
	
	for (; environ[place] != NULL ; place++)
	{
		if (environ[place][0] == 'P' && environ[place][2] == 'T')
		{
			path_of_token = _which(environ[place]);
		}
	}
	return (path_of_token);
}

/**
 *  _itoa - integer to ascii value
 *  @temp_num: the integer
 *  @base: the base
 *  Return: char
 *  Reference: https://gist.github.com/narnat/95733cd0ad7bfac0d90697292914c407
 */

char *_itoa(int temp_num, int base)
{
	static char *holder = "0123456789abcdef";
	static char buff[50];
	char init_sign = 0;
	char *pointer;
	unsigned long l = temp_num;

	if (temp_num < 0)
	{
		l = -temp_num;
		init_sign = '-';
	}
	pointer = &buff[49];
	*pointer = '\0';
	
	do      {
		*--pointer = holder[l % base];
		l /= base;
	} while (l != 0);

	if (init_sign)
		*--pointer = init_sign;
	return (pointer);
}

/**
 * _strdup - duplicates a strings
 * @temp_str: The string to be duplicated
 * Return: the pointer of the concat string
 **/
char *_strdup(char *temp_str)
{
	int n, m;
	char *temp = NULL;

	if (temp_str == NULL)
		return (0);
	for (n = 0; temp_str[n]; n++)
		;
	n++;
	temp = malloc(n * sizeof(char *));
	if (!temp)
		return (NULL);
	for (m = 0; m < n; m++)
	{
		temp[m] = temp_str[m];
	}
	return (temp);
}
