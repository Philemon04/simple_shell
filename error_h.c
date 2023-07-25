#include "header.h"

/**
 * get_input - ends the prompt with a new line and handles CTRL + C
 * @input: the input passed
 *
 */
void get_input(int input)
{
	char *prompt = {"\n#myshell$ "};
	(void) input;

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	fflush(stdout);
}

/**
 * _stat - check the status of file
 * @cmd: the command pointer
 * @path: the path of the directories
 * Return: 1
 **/
int _stat(char **cmd, char **path)
{
	char *first_string = NULL, *final_string = NULL;
	int counter;

	struct stat sb;

	if (path == NULL)
	{
		free(path);
		free(cmd);
		return (0);
	}

	for (counter = 0; path[counter] != NULL ; counter++)
	{
		first_string = str_concat(path[counter], "/");
		final_string = str_concat(first_string, cmd[0]);
		if (stat(final_string, &sb) == 0 && (sb.st_mode & S_IXUSR))
		{
			cmd[0] = final_string;																			free(first_string);
			free(path[0]);
			free(path);
			return (1);
		}
		free(first_string);
		free(final_string);
	}
	free(path[0]);
	free(path);
	return (0);
}

