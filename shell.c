#include "main.h"

/**
 * main - Simple shell
 * @argc: argument count
 * @env: environment
 *
 * Return: Always 0
 */
int main(int argc, char **env)
{
	(void)argc;

	char *string = NULL;
	size_t size = 0;
	ssize_t chars_read;

	char **c_array = NULL;
	int n_spaces = 0;

	pid_t child_pid;
	int status;

	char *full_path = NULL;

	while (1)
	{
		if (isatty(0))
			print_string("$ ");

		chars_read = getline(&string, &size, stdin);
		if (chars_read < 0)
		{
			free(string);
			exit(0);
		}

		if (string[chars_read - 1] == '\n')
			string[chars_read - 1] = '\0';

		/* Free memory from the previous iteration */
		for (int i = 0; i < n_spaces; ++i)
		{
			free(c_array[i]);
		}
		free(c_array);

		/* Reset counters and pointers*/
		n_spaces = 0;
		c_array = NULL;

		char *token = strtok(string, " ");

		while (token)
		{
			c_array = realloc(c_array, sizeof(char *) * (n_spaces + 1));
			if (c_array == NULL)
			{
				perror("Error reallocating memory");
				return (-1);
			}
			c_array[n_spaces++] = strdup(token);
			token = strtok(NULL, " ");
		}
		c_array = realloc(c_array, sizeof(char *) * (n_spaces + 1));
		c_array[n_spaces] = NULL;



		if (c_array[0][0] == '/')
		{
			if (!access(c_array[0], X_OK) == 0)
			{
				print_string("command not found\n");
				continue;
			}
		}
		else
		{
			char *sys_path = getenv("PATH");

			full_path = get_full_path(sys_path, c_array[0]);

			if (full_path != NULL)
			{
				c_array[0] = full_path;
				print_string(full_path);
				print_string("\n");
			}
			else
			{
				int res = check_built_in(c_array);

				if (res != 0)
				{
					print_string("command not found\n");
				}
				continue;
			}
		}


		child_pid = fork();
		if (child_pid == -1)
		{
			print_string("Error:");
			free(string);
			exit(0);
		}

		if (child_pid == 0)
		{
			if (execve(c_array[0], c_array, env) == -1)
			{
				print_string("Error:");
			}
			return (0);
		}
		else
		{
		    wait(&status);
		}
	}

	free(string);
	for (int i = 0; i < n_spaces; ++i)
	{
		free(c_array[i]);
	}
	free(c_array);

	return (0);
}
