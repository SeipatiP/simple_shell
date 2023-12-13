#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * display_prompt - A user prompt
 *
 * Description: Function displays an instruction for user input.
 */

void display_prompt(void)
{
	printf("SimpleShell> ");
}

/**
 * main - Entry point of the program
 * Description: Function used to initialize variables
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing command-line arguments.
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char command[181];

	while (1)
	{
		display_prompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nGoodbye!\n");
		}

		break;

		command[strcspn(command, "\n")] = '\0';

		char *env[] = {"VAR1=123", "VAR2=456", NULL};
		char *command_and_args[128];
		char *token = strtok(command, " ");
		int i = 0;

		while (token != NULL)
		{
			command_and_args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}

		command_and_args[i] = NULL;
		execve(command_and_args[0], command_and_args, env);

		perror("execve");
	}

	return (0);
}
