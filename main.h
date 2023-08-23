#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_ARGS 64

#define MAX_TOKENS 11

int _putchar(char c);
int print_string(char *str);

void tokenize_input(char *input, char **token_array, int *num_tokens);

void process_input(char **token_array, int num_tokens);

#endif
