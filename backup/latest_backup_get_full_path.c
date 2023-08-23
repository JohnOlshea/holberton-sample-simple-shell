#include "main.h"

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
			return NULL;
		}

		strcpy(concat_path, path_token);
		strcat(concat_path, "/");
		strcat(concat_path, argv);

		if (access(concat_path, X_OK) == 0)
		{
			printf("%s\n", concat_path);
			return (concat_path);
		}

		/*printf("%s\n", concat_path);*/
		free(concat_path);
		path_token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
