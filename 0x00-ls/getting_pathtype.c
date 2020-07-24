#include "ls.h"
/**
 * getting_pathtype - Just printing without options
 * @ac: number of arguments on the original program
 * @av: Array of arguments from command line
 * @options: Printing options
 * Return: 0 if sucessful, otherwise 1
 */
int getting_pathtype(int ac, char **av,  char *options)
{
	int i, e = 0;
	dfileinfo_t *files = NULL, *dirs = NULL, *aux = NULL;
	struct stat info;
	char *name;

	for (i = 1; i < ac; i++)
	{
		if (av[i][0] != '-' || (_strcmp(av[i], "-") == 0))
		{
			name = av[i];
			if (lstat(av[i], &info) != 0)
			{
				denied_access(name, ac, 1);
				e = 1;
			}
			else if (S_ISREG(info.st_mode) || S_ISLNK(info.st_mode))
				addfileinfo(&files, name, info);
			else if (S_ISDIR(info.st_mode))
				addfileinfo(&dirs, name, info);
		}
	}
	printing_nodes(files, options);
	if (files != NULL && dirs != NULL)
		printf("\n");
	aux = dirs;
	while (aux != NULL)
	{
		if ((aux->next != NULL || aux->prev != NULL) || e == 1 || files != NULL)
			printf("%s:\n", aux->name);
		getting_info_dir(0, aux->name, options);
		if ((ac > 2 && aux->next != NULL) ||
		    (aux->next == NULL && _strchr(options, 'a') == 1))
			printf("\n");
		if (aux->next != NULL && (options != NULL && _strchr(options, '1') == 0))
			printf("\n");
		aux = aux->next;
	}
	free_fileinfo(files);
	free_fileinfo(dirs);
	return (0);
}
