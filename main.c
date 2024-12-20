#include "shell.h"

int main(int argc, char **argv)
{
        
        char *input = NULL;
        size_t input_size = 0;
        ssize_t nread;
        pid_t child_pid;        
        int status;
        int i = 0;

        (void)argc, (void)argv;


        while (1)
        {
                if (isatty(STDOUT_FILENO))
                printf("$ ");

                nread = getline(&input, &input_size, stdin);

                if (strcmp(&input[i], "exit") == 0)
                {
                        free(input);
                        exit(0);
                }

                if (nread ==  -1)
                {
                        perror("Exiting shell");
                        exit(1);
                }

                child_pid = fork();

                if (child_pid == -1)
                {
                        perror("Failed to create.");
                        exit (41);
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
        }
        free(input);
        return (0);
}
