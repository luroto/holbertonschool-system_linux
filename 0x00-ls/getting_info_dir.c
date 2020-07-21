#include "ls.h"
/**
 *getting_info_dir - Stores the readdir entries of a directory on
 *a doubly linked list
 *@ac: # of arguments
 *@pathname: Name of the directory
 *@options: Options for printing
 *Return: 0 if sucessful
 */

int getting_info_dir(int ac, char *pathname, char *options)
{
	DIR *dir;
	struct dirent *entry;
	dfilelist_t *hfl, *hdr;

	dir = opendir(pathname);
	if (dir == NULL)
		return (denied_access(pathname, ac, 1));
	hfl = NULL;
	hdr = NULL;
	for (entry = readdir(dir); entry != NULL; entry = readdir(dir))
	{
		if (entry->d_type == 8 || entry->d_type == 10)
			addftend(&hfl, entry->d_name, entry->d_type);
		else
		{
			if (entry->d_type == 4)
				addftend(&hdr, entry->d_name, entry->d_type);
		}
	}
	if (closedir(dir) != 0)
		major_trouble();
	if (hfl != NULL && hdr != NULL)
		link_lists(&hfl, hdr);
	if (hfl == NULL)
		hfl = hdr;
	getting_stats(hfl, pathname, options);
	if (hfl != NULL)
		free_dfilelist(hfl);
	return (0);
}
