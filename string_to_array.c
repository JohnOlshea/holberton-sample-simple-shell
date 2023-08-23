#include "main.h"

int string_to_array(char *string, char ***result_array, size_t *array_size) {
	for (size_t i = 0; i < *array_size; ++i)
	{
		free((*result_array)[i]);
	}
	free(*result_array);

	*array_size = 0;
	*result_array = NULL;

	char *token = strtok(string, " ");
	while (token)
	{
		*result_array = realloc(*result_array, sizeof(char *) * (*array_size + 1));
	if (*result_array == NULL)
	{
		perror("Error reallocating memory");
		return (-1);
	}
		(*result_array)[*array_size++] = strdup(token);
		token = strtok(NULL, " ");
	}
	*result_array = realloc(*result_array, sizeof(char *) * (*array_size + 1));
	(*result_array)[*array_size] = NULL;

	return 0;
}
