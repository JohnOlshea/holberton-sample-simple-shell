#include "main.h"

int main(int argc, char **env)
{
	(void)argc;

	char *string = NULL;
	size_t size = 0;
	ssize_t chars_read;

	char **c_array = NULL;
	size_t array_size = 0;

	pid_t child_pid;
	int status;	

char *full_path = NULL;

	while (1)
	{
		printf("$ ");
		chars_read = getline(&string, &size, stdin);
		if (chars_read < 0)
		{
			/*perror("");*/
			free(string);
			exit(0);
			/*return (1);*/
		}

		if (string[chars_read - 1] == '\n')
			string[chars_read - 1] = '\0';


		string_to_array(string, &c_array, &array_size);

		/*for (size_t i = 0; i < array_size; ++i)
		{
			printf("%s\n", c_array[i]);
		}*/


		if (c_array[0][0] == '/')
		{
			if (!access(c_array[0], X_OK) == 0)
			{
				printf("Command does not exist.\n");
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
				printf("Full path: %s\n", full_path);
			}
			else
			{
				/*check if builtin*/
				int res = check_built_in(c_array);
				if (res != 0)
				{
					printf("command not found %d\n", res);
				}
				continue;
			}
		}


		



		child_pid = fork();
		if (child_pid == -1)
		{
		perror("Error:");
		return (1);
		}

		if (child_pid == 0)
		{
			if (execve(c_array[0], c_array, env) == -1)
			{
				perror("Error:");
			}
			return (0);
		}
		else
		{
		    wait(&status);
		}
	}

// Free memory at the end
free(string);

/*for (size_t i = 0; i < array_size; ++i)
{
	free(c_array[i]);
}*/

free(c_array);


			free(full_path);
return (0);


}
