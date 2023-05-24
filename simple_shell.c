#include "header.h"
#include <sys/wait.h>
#include <sys/types.h>

/**
 * prompt - method prints '$' and gets ready for input
 */

void prompt(void)
{
	char *prompt = {"cisfun"};
	char *buffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
	free(buffer);
}

/**
 * read_command - reads the input and converts it to stdin
 * Return: void
 */

char *read_command(void)
{
	char *entry = NULL;
	ssize_t signal;
	size_t bufsize = 0;
	int j;

	signal = getline(&entry, &bufsize, stdin);
	if (!entry)
	{
		perror("Error when allocating memory for buffer");
		return (0);
	}
	if (signal == 1)
	{
		free(entry);
		return (NULL);
	}
	else if (signal == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(entry);
		exit(0);
	}
	else
	{
		for (j = 0; entry[j] == ' ' && entry[j + 1] == ' '; j++);
		if (!entry[j] && entry[j + 1] == '\n')
			{
				free(entry);
				return (0);
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

char **get_array_from_str(char *str, char **env)
{
	int buffersize = token_Bufsize, position = 0;
	char **entry;
	char *entry1;

	if (str == NULL)
	{
		return (0);
	}
	entry = _calloc(sizeof(char *), buffersize);
	if (!entry)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	entry1 = strtok(str, token_Delim);
	while (entry1 != NULL)
	{
		entry[position] = entry1;
		position++;
		entry1 = strtok(NULL, token_Delim);
	}
	if (entry[0] == NULL)
		entry[position] = "\n";

	if ((_strcmp(entry[0], "exit") == 0) && entry[1] == NULL)
	{
		free(str);
		free(entry);
		exit(0);
	}
	if ((_strcmp(entry[0], "env") == 0) && entry[1] == NULL)
		print_shell(env);
	
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
	char *copy_path = NULL, *entry =  NULL, *separator = ":=";
	char **dir = _calloc(sizeof(char *), size);

	if (foundpath == NULL)
	{
		free(foundpath);
		return (0);
	}
	if (dir == NULL)
	{
		free(foundpath);
		perror("Error in allocated memory");
		return (NULL);
	}

	copy_path = _stdrup(foundpath);
	entry = strtok(copy_path, separator);
	while (entry != NULL)
	{
		dir[j] = entry;
		j++;
		entry = strtok(NULL, separator);
	}

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

int executable_command(char **av, char **args, char **env, int status_main, int count)
{
	pid_t pid;
	int status;

	if (args == NULL)
		return (-1);

	pid = fork();
	if (pid < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			_error(av[0], count, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (status_main == 1)
			free(args[0]);

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
