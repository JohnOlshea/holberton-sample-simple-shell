#include "main.h"

/**
 * get_full_path - appends full path to command
 * @path: env path
 * @argv: command array
 *
 * Return: On success NULL
 */
char *get_full_path(char *path, char *argv)
{
	char *path_copy, *path_token, *concat_path;

	path_copy = strdup(path);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		size_t path_token_len = strlen(path_token);
		size_t argv_len = strlen(argv);

		concat_path = malloc(path_token_len + argv_len + 2);
		if (concat_path == NULL)
		{
			perror("Error allocating memory");
			free(path_copy);
			return (NULL);
		}
		strcpy(concat_path, path_token);
		strcat(concat_path, "/");
		strcat(concat_path, argv);

		struct stat st;

		if (stat(concat_path, &st) == 0 && st.st_mode & S_IXUSR)
		{
			free(path_copy);
			return (concat_path);
		}
		free(concat_path);
		path_token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
