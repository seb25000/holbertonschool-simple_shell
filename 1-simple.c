#include "shell.h"


/**
 * main - Main block
 *
 * Return: 0
 */

int main(void)
{

while (1)

{
if (isatty(STDIN_FILENO))
{
printf("$");
fflush(stdout);
while (1);
}
}
return (0);
}

if (child_pid == 0)
                {
                        /* The creation was successful and we can execute the user input */
                        printf("The creation was successful\n");
                }
                
                else
                {
                        /* Wait for the child process to execute before terminating the parent process */
                        wait(&status);
                }