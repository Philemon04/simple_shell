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
 * 
