#include "header.h"

/**
* start_prompt - method prints prompt and gets ready for input
* Return: void
*/
void start_prompt(void)
{
	char *prompt = {"#myshell$ "};
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
	size_t buffersize = 0;
	int i;

	signal = getline(&entry, &buffersize, stdin);
	if (!entry)
	{
		perror("Error allocating memory for buffer");
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
		for (i = 0; entry[i] == ' ' && entry[i + 1] == ' '; i++)
			;
		if (!entry[i] && entry[i + 1] == '\n')
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
	int buffersize = TOK_BUFFERSIZE, pos = 0;
	char **tokens;
	char *token;

	if (str == NULL)
	{
		return (0);
	}
	tokens = _calloc(sizeof(char *), buffersize);
	if (!tokens)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, TOK_DELIM);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, TOK_DELIM);
	}
	if (tokens[0] == NULL)
		tokens[pos] = "\n";
	if ((_strcmp(tokens[0], "exit") == 0) && tokens[1] == NULL)
	{
		free(str);
		free(tokens);
		exit(0);
	}
	if ((_strcmp(tokens[0], "env") == 0) && tokens[1] == NULL)
		print_shell(env);

	return (tokens);
}

/**
* _which - checks the args of the input to determine the path
* @foundpath: the input being passed
* * Return: returns the complete path or 0 if not found
*/

char **_which(char *foundpath)
{
	int size = TOK_BUFFERSIZE, i = 0;
	char *copy_path = NULL, *tokens = NULL, *sparse = ":=";
	char **dir = _calloc(sizeof(char *), size);

	if (foundpath == NULL)
	{
		free(foundpath);
		return (0);
	}
	if (dir == NULL)
	{
		free(foundpath);
		perror("Error allocated memory");
		return (NULL);
	}

	copy_path = _strdup(foundpath);
	tokens = strtok(copy_path, sparse);
	while (tokens != NULL)
	{
		dir[i] = tokens;
		i++;
		tokens = strtok(NULL, sparse);
	}

	return (dir);
}

/**
* exe_command - checks if the input is an executable command
* @args: the input to be checked
* @env: environment variable
* @status_main: status variable
* @av: name of program
* @count: count of the entry
* Return: 1
*/
int exe_command(char **av, char **args, char **env, int status_main, int count)
{
	pid_t pid;
	int status;

	if (args == NULL)
		return (-1);

	pid = fork();
	if (pid  < 0)
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
