#include "shell.h"
#define MAX_LINE 1024
/**
 * read_line - function that Read a user-entered command line.
 * _getenv - Get an environment variable.
 * Return: The environnment variable, if not found NULL
 */

char *read_line(void)
{
char *line = malloc(MAX_LINE * sizeof(char));
if (!line)
{
perror("malloc");
exit(1);
}
fgets(line, MAX_LINE, stdin);
return (line);
}
/**
 * split_line - Splits a command line into multiple arguments.
 * @line: is pointer
 * Return: args
 */

char **split_line(char *line)
{
int bufsize = 64;
int position = 0;
char **args = malloc(bufsize * sizeof(char *));
char *token;

if (!args)
{
perror("malloc");
exit(1);
}

token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
args[position] = token;
position++;

if (position >= bufsize)
{
bufsize += 64;
args = realloc(args, bufsize *sizeof(char *));
if (!args)
{
perror("realloc");
exit(1);
}
}

token = strtok(NULL, " \t\r\n\a");
}
args[position] = NULL;
return (args);
}
/**
 * execute - Executes the given command using execvp.
 * @args: is double pointer to char
 * Return: 1
 */

int execute(char **args)
{
pid_t pid;
int status;

pid = fork();

if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("execvp");
}
exit(1);
}
else if (pid < 0)
{
perror("fork");
}
else
{
do {
pid = waitpid(pid, &status, WUNTRACED);

} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
/**
 * shell_loop - Main shell loop. It reads and executes commands
 * until the user exits the shell.
 * Return: void
 */

void shell_loop(void)
{
char *line;
char **args;
int status;

do {
printf("> ");
line = read_line();
args = split_line(line);
status = execute(args);

free(line);
free(args);
} while (status);
}
