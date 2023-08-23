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

int _putchar(char c);
int print_string(char *str);
char *get_full_path(char *path, char *argv);
int check_built_in(char **argv);
int string_to_array(char *string, char ***result_array, size_t *array_size);

#endif
