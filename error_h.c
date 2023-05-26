#include "header.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * get_input - ends the prompt with a new line and handles CTRL + C
 * @input: the input passed
 *
 */
void get_input(int input __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n#myshell$ ", 11);
}

/**
 * _stat - check the status of file
 * @cmd: the command pointer
 * @path: the path of the directories
 * Return: 1
 */
int _stat(char **cmd, char **path)
{
	char *concat_str;
	char *divider = "/";
	int count;

	struct stat sb;

	if (cmd[0][0] == '/' || cmd[0][0] == '.')
	{
		if (stat(cmd[0], &sb) == 0)
			return (1);
	}
	else
	{
		for (count = 0; path[count] != NULL; count++)
		{
			concat_str = malloc((strlen(path[count]) +
						strlen(cmd[0]) + 2) * sizeof(char));
			if (concat_str == NULL)
			{
				perror("Error");

				return (0);
			}

			concat_str = _strcat(_strcpy(concat_str, path[count]), slash);
			concat_str = _strcat(concat_str, cmd[0]);

			if (stat(concat_str, &sb) == 0)
			{
				free(cmd[0]);
				cmd[0] = _strdup(concat_str);
				free(concat_str);
				return (1);
			}

			free(concat_str);
		}
	}

	return (0);
}

/**
 * _error - stdout error of file
 * @argv: name of the program
 * @count: number of prompt
 * @args: commands to be passed
 * Return: 0
 */
int *_error(char *argv, int count, char *args)
{
	char *num;

	num = _itoa(count, 10);
	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, num, _strlen(num));
	write(2, ": ", 2);
	write(2, args, _strlen(args));
	perror(" ");

	return (0);
}
