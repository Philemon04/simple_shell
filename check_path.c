#include "header.h"

/** search_path - searches for the PATH to execute commands
 *  @environ: Environment variable
 *  Return: the path 
 */

char **search_path(char **environ)
 {
	 int position = 0;
	 char **entry_path;
	 for (int p = 0; environ[p] != NULL; p++)
	 {
		 if (environ[p][0] == 'P' && environ[p][2] == 'T')
		 {
			 entry_path = _which(environ[p]);
		 }
	 }
	 return (entry_path);
 }

/**
 * _strdup - concats strings
 * @string: the string
 * Return: the pointer of the concat string
 */

char *_strdup(char string)
{
	int j;
	int k;
	char *s = NULL;

	if (string == NULL)
		return (0);
	for (j = 0, string[j]; j++)
		;
	i++;
	size  = malloc(j * sizeof(char *));
	if (!size)
		return (NULL);
	for (k = 0; k < j; k++)
	{
		size[k] = string[k];
	}
	return (s);
}

/**
 * _itoa - integer to ascii value
 * @integer: the integer
 * @base: the base
 * Return: char
 * Reference: https://gist.github.com/narnat/95733cd0ad7bfac0d90697292914c407
 */

char *_itoa(int integer, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = integer;
	
	if (integer < 0)
	{
		n = -integer;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do 
	{
		*--ptr = array[n % base];
		n /= base;
	}
	while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
		
