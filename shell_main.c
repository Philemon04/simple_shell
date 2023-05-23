#include "header.h"

/**
 * main - is the main shell main method
 * @ac: no of arguments
 * @av: array of arguments
 * @env: environment variable
 * Return: EXIT_SUCCESS
 */
int main(int ac _attribute_((unused)), char **av, char ** env)
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

		if((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env" != 0))
		{
				count += 1;
				path = search_path(env);
				status = _stat(args, path);
				child_process(av, args, env, status, count);
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

	for (j = 0; env[j]; j++
			_puts(env[j]);
}
