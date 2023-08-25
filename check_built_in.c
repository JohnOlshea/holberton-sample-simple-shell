#include "main.h"

/**
 * check_built_in - checks for built-in commands
 * @arg: command
 *
 * Return: 0 (Success) or 1 (Error)
 */
int check_built_in(char **arg)
{
	/**
	 * if (strcmp(arg[0], "exit") == 0)
	 * {
	 * exit(0);
	 * }
	 * */
	if (strcmp(arg[0], "exit") == 0)
	{
		/*printf("%d\n", errno);*/
		/*if (errno != 0)
		{
			exit (5);
		}*/
		exit (0);
		/*exit (errno);*/
	}

else if (strcmp(arg[0], "env") == 0)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return 0;
}

	else if (strcmp(arg[0], "cd") == 0)
	{
		printf("%d\n", errno);
		if (arg[1] == NULL)
		{
			if (chdir(getenv("HOME")) != 0)
			{
				perror("chdir");
				return (1);
			}
		}
		else
		{
			if (chdir(arg[1]) != 0)
			{
				perror("chdir");
				return (1);
			}
		}
		return (0);
	}
	return (1);
}
