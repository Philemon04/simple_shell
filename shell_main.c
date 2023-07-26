#include "header.h"

/**
* main - is the main shell main method
* @ac: no of arguments
* @av: array of arguments
* @env: environment variable
* Return: EXIT_SUCCESS
*/
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *position;
	char **args, **path;
	int counter = 0, state = 0;
	(void) av;
	input(SIGINT, get_input);
	while (1)
	{
		prompt();
		/*read input and return string*/
		position = read_command();																		/*separates string to get command and atgs*/
		args = get_array_from_str(position, env);

		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
		{
			counter += 1;
			path = search_path(env); /*busca PATH en la variable environ*/
			state = _stat(args, path);
			executable_command(av, args, env, state, counter);
		}
		else
		{
			free(args);
		}
		free(position);
	}
	return (EXIT_SUCCESS);
}
