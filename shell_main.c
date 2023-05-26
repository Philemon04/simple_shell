#include "header.h"
#include <sys/signal.h>

/**
 * main - is the main shell main method
 * @ac: no of arguments
 * @av: array of arguments
 * @env: environment variable
 * Return: EXIT_SUCCESS
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *entry;
	char **args;
	char **path;
	int count = 0;
	int status = 0;
	(void) av;
	signal(SIGINT, get_input);

	while (1)
	{
		start_prompt();
		entry = read_command();
		args = get_array_from_str(entry, env);

		if (args && args[0] && (_strcmp(args[0], "\n")  != 0) &&
				(_strcmp(args[0], "env") != 0))
		{
				count += 1;
				path = search_path(env);
				status = _stat(args, path);
				executable_command(av, args, env, status, count);
		}
		else
		{
			free(args);
		}
		free(entry);
	}
	return (EXIT_SUCCESS);
}

/**
 * print_shell - prints the current environment
 * @env: environmnet variable
 */
void print_shell(char **env)
{
	int j;

	for (j = 0; env[j]; j++)
	{
		_puts(env[j]);
	}
}

/**
 * _calloc - allocates memory for numb elements of size bytes
 * @numb: number of elements in the array
 * @size: bytes for the positions in the array
 * Return: void
 */
void *_calloc(unsigned int numb, unsigned int size)
{
	void *pointer;
	unsigned int j = numb * size;
	unsigned int k;
	char *pointer2;

	if (numb == 0 || size == 0)
		return (NULL);

	pointer = malloc(j);
	if (pointer == NULL)
		return (NULL);
	pointer2 = (char *)pointer;

	for (k = 0; k < j; k++)
	{
		pointer2[k] = 0;
	}

	return (pointer);
}

/**
 * _malloc - it does something
 * @size -  size to be checked
 * Return: void
 */
void *_malloc(size_t size)
{
	return malloc(size);
}

/**
 * strcat - copy source string to destination
 * @destination - destination
 * @org - origin
 * Return: destination
 */
char *_strcat(char *destination, char *org)
{
	char *pointer = destination;

	while (*pointer)
		pointer++;

	while (*org)
	{
		*pointer = *org;
		pointer++;
		org++;
	}

	*pointer = '\0';

	return destination;
}
