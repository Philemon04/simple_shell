#include "header.h"

/** search_path - searches for the PATH to execute commands
 *  @environ: Environment variable
 *  Return: the path 
 */

char **search_path(char **environ)
 {
	 int position = 0;
	 char **entry_path;
	 for (int p = 0; environ[p] != NULL; p++)
	 {
		 if (environ[p][0] == 'P' && environ[p][2] == 'T')
		 {
			 entry_path = _which(environ[p]);
		 }
	 }
	 return (entry_path);
 }
