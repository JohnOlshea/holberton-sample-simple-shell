#include "main.h"

char *get_full_path(char *path, char *argv)
{
        char *path_token, *concat_path = NULL;

        char *path_cpy;
        path_cpy = strdup(path);


        path_token = strtok(path_cpy, ":");
        concat_path = malloc(strlen(argv) + strlen(path_token) + 2);
        while (path_token != NULL)
        {
                strcpy(concat_path, path_token);
                strcat(concat_path, "/");
                strcat(concat_path, argv);
                strcat(concat_path, "\0");

                if (access(concat_path, X_OK) == 0)
                {
                        /*printf("%s\n", concat_path);*/
                        return (concat_path);
                }

                /*printf("%s\n", concat_path);*/
                path_token = strtok(NULL, ":");
        }
free(concat_path);
return (NULL);
}
