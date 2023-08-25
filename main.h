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
int _putchar_err(char c);
int print_string_err(char *str);
int print_string(char *str);
char *get_full_path(char *path, char *argv);
int check_built_in(char **arg);

#endif
