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
			break;
		}

		command[strcspn(command, "\n")] = '\0';
		char *env[] = {"VAR1=123", "VAR456", NULL};

		if (execve("/bin/sh", (char *[])
		{"/bin/sh", "-c", command, NULL}, env) == -1)
		{
			perror("execve");
			return (1);
		}
	}

	return (0);
}
