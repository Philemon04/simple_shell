#include "header.h"
#include <sys/wait.h>
#include <sys/types.h>

/**
 * start_prompt - method prints prompt and gets ready for input
 * Return: void
 */
void start_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#myShell$ ", 10);
	}
}

/**
 * read_command - reads the input and converts it to stdin
 * Return: void
 */
char *read_command(void)
{
	char *entry = NULL;
	ssize_t signal = 0;

	if (getline(&entry, &signal, stdin))
	{
		if (feof(stdin))
		{
			_puts("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	return (entry);
}

/**
 * get_array_from_str - forms an array of string from a string
 * @str: string to be passed
 * @env: environment variable
 * Return: returns array of strings or exits
 */

char **get_array_from_str(char *str, char **env __attribute__ ((unused)))
{
	int i = 0, position = 0;
	char **entry;
	char *entry1;

	entry = _calloc(1024, sizeof(char *));
	if (entry == NULL)
	{
		perror("Error");
		return (NULL);
	}
	entry1 = strtok(str, " \n");
	while (entry1 != NULL)
	{
		if (_strcmp(entry1, "$") == 0)
		{
			free(entry[i - 1]);
			entry[i - 1] = _strdup("env");
		}
		else if (_strcmp(entry1, "$?") == 0)
		{
			free(entry[i]);
			entry[i] = _itoa(status);
		}
		else if (_strcmp(entry1, "$$") == 0)
		{
			free(entry[i]);
			entry[i] = _itoa(getpid());
		}
		else 
		{
			entry[i] = _strdup(entry1);
			position++;
		}

		entry1 = strtok(NULL, " \n");
		i++;
	}

	entry[position] = NULL;

	return (entry);
}

/**
 * _which - checks the args of the input to determine the path
 * @foundpath: the input being passed
 * Return: returns the complete path or 0 if not found
 */

char **_which(char *foundpath)
{
	int size  = token_Bufsize, j = 0;
	char *copy_path;
	char **dir = _malloc(size *  sizeof(char *));

	if (dir == NULL)
	{
		perror("Error");
		return (NULL);
	}

	copy_path = strtok(foundpath, ":");
	while (copy_path != NULL)
	{
		dir[j] = _strdup(copy_path);
		j++;
		copy_path = strtok(NULL, ":");
	}

	dir[j] = NULL;

	return (dir);
}

/**
 * executable_command -  checks if the input is an executable command
 * @args: the input to be checked
 * @env: environment variable
 * @status_main: status variable
 * @av: name of program
 * @count: count of the entry
 * Return: 1
 */
void executable_command(char **av, char **args, char **env, int status_main, int count)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("./hsh: ");
		return;
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(av[0]);
			free(args);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			status_main = WEXITSTATUS(status);
	}
}
