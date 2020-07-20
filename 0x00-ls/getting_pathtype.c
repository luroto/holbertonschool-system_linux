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
	int i;
	dfileinfo_t *files, *dirs, *aux;
	struct stat info;
	char *name;

	files = NULL;
	dirs = NULL;
	aux = NULL;
	for (i = 1; i < ac; i++)
	{
		if (av[i] != options)
		{
			name = av[i];
			if (lstat(av[i], &info) != 0)
			{
				denied_access(name, ac, 1);
			}
			else if (S_ISREG(info.st_mode) || S_ISLNK(info.st_mode))
				addfileinfo(&files, name, info);
			else if (S_ISDIR(info.st_mode))
				addfileinfo(&dirs, name, info);
		}
	}
	printing_nodes(files, options);
	aux = dirs;
	while (aux != NULL)
	{
		if (ac > 2)
			printf("%s:\n", aux->name);
		getting_info_dir(0, aux->name, options);
		if (ac > 2 && aux->next != NULL)
			printf("\n");
		aux = aux->next;
	}
	free_fileinfo(files);
	free_fileinfo(dirs);
	return (0);
}
