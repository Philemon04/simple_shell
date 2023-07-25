fndef _HEADER_H_
#define _HEADER_H_
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#define TOK_BUFFERSIZE 64
#define TOK_DELIM " \t\r\n\a"
extern char **environ;

void get_input(int input);
int exit_shell(char **args);
void print_shell(char **env);
void executable_command(char **argv, char **args, char **environ, int string, int counts);
int _strlen(const char *len);
int _strcmp(char *string1, char *string2);
char *_strstr(char *string1, char *substring);
char *_strdup(char *string);
char *_strcat(char *destintn, char *sourc);
char *_strcpy(char *destintn, char *sourc);
char *_itoa(int integer);
char *read_command(void);
char **get_array_from_str(char *str, char **env);
void start_prompt(void);
void *_realloc(void *ptr, unsigned int size);
int _count_buffer(char *buffer);
void *_calloc(unsigned int numb, unsigned int size);
char **search_path(char **environ);
int _stat(char **cmd, char **path);
char *str_concat(char *string1, char *string2);
void _puts(char *str);
int _putchar(char c);

int execute(char **args, char **argv, int count, char *str, char **env);
int _access(char *filename);
void *_malloc(size_t size);

int *_error(char *argv, int count, char *argc);
char **_which(char *foundpath);

#endif
