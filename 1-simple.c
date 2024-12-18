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

