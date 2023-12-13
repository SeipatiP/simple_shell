#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

int main(int argc, char *argv[]);
void display_prompt(void);
void receive_command(char *command, size_t size);
void execute_command(const char *command);
extern char **environ;

#endif /* SHELL_H */

