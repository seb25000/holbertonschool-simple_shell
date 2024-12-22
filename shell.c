#include "shell.h"

/**
 * main - Main block
 * @argc: is an integer
 * @argv: is a double pointer
 * Return: 0
 */

int main(int argc, char **argv)
{
char *input = NULL;
size_t count = 0;
ssize_t nread;
(void)argc, (void)argv;

while (1)
{
write(STDOUT_FILENO, "$ ", 2);

nread = getline(&input, &count, stdin);

if (nread == -1)
{
free(input);
exit(0);
}

if (strcmp(input, "exit\n") == 0)
{
free(input);
exit(0);
}

if (strcmp(input, "env\n") == 0)
{
printf("env command entered\n");
continue;
}
}
}
