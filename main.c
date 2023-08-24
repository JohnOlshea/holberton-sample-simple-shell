#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	char *string = NULL;
	size_t size = 0;
	ssize_t chars_read;

	char *c_array[11];
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
			print_string("\n");
			free(string);
			exit(0);
		}

		if (string[chars_read - 1] == '\n')
			string[chars_read - 1] = '\0';

		c_array[n_spaces] = strtok(string, " ");
		while (c_array[n_spaces])
		{
			n_spaces++;
			c_array[n_spaces] = strtok(NULL, " ");
		}

		if (n_spaces <= 0)
			continue;

		/**
		 * for (i = 0; i < (n_spaces + 1); ++i)
		 * printf("res[%d] = %s\n", i, c_array[i]);
		 */

		n_spaces = 0;


		if (!access(c_array[0], X_OK) == 0)
		{

			char *sys_path = getenv("PATH");

			full_path = get_full_path(sys_path, c_array[0]);

			if (full_path != NULL)
			{
				c_array[0] = full_path;
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
			if (execve(c_array[0], c_array, NULL) == -1)
			{
				print_string("No such file or directory\n");
			}
			return (0);
		}
		else
		{

			wait(&status);
		}
	}

	free(string);
	return (0);
}
