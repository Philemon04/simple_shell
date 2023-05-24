#include "header.h"
#include <sys/wait.h>
#include <sys/types.h>

/**
 * get_input - ends the prompt with a new line and handles CTRL + C
 * @input: the input passed
 *
 */ 
void get_input(int input)
{
	char *prompt = {"\ncisfun"};
	(void) input;

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	fflush(stdout);
}

/**
 * _stat - check the status of file
 * @cmd: the command pointer
 * @path: the path of the directories
 * Return: 1
 */
int _stat(char **cmd, char **path)
{
	char *concat_str = NULL;
        char *new_str = NULL;
	int count;

	struct stat sb;

	if (path == NULL)
	{
		free(path);
		free(cmd);
		return (0);
	}

	for (count = 0; path[count] != NULL; count++)
	{
		concat_str = str_concat(path[count], "/");
		new_str = str_concat(concat_str, cmd[0]);
		if (stat(new_str, &sb) == 0 && (sb.st_mode & S_IXUSR))
		{
			cmd[0] = new_str;
			free(concat_str);
			free(path[0]);
			free(path);
			return (1);
		}
		free(concat_str);
		free(new_str);
	}
	free(path[0]);
	free(path);
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
