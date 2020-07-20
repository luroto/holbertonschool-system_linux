#include "ls.h"
/**
 * getting_stats - Checking directories content
 * @h: Pointer to a DLL for entry info
 * @dph: path to be researched
 * @options: Printing options
 * Return: 0 if sucessful, otherwise 1
 */
int getting_stats(dfilelist_t *h, char *dph, char *options)
{
	dfilelist_t *a;
	dfileinfo_t *files, *dirs;
	struct stat info;
	char *fullpath;
	char *slash;

	slash = "/";
	files = NULL;
	dirs = NULL;
	for (a = h; a != NULL; a = a->next)
	{
		if (_strcmp(dph, "/") == 0)
		{
			fullpath = malloc(_strlen(dph) + _strlen(a->name) + 2);
			_strcpy(fullpath, dph);
			_strcat(fullpath, a->name);
		}
		else
		{
			fullpath = malloc(_strlen(dph) + _strlen(a->name) + 3);
			_strcpy(fullpath, dph);
			_strcat(fullpath, slash);
			_strcat(fullpath, a->name);
		}
		if (lstat(fullpath, &info) != 0)
			denied_access(fullpath, 0);
		if (S_ISREG(info.st_mode) || S_ISLNK(info.st_mode))
			addfileinfo(&files, a->name, info);
		if (S_ISDIR(info.st_mode))
			addfileinfo(&dirs, a->name, info);
		free(fullpath);
	}
	if (files != NULL && dirs != NULL)
		link_filedatas(&files, dirs);
	else if (files == NULL)
		files = dirs;
	printing_nodes(files, options);
	if (files != NULL)
		free_fileinfo(files);
	return (0);
}
