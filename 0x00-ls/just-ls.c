#include "ls.h"
/**
 * just_ls - Just printing without options
 * @pathname: path to be researched
 * @ac: number of arguments on the original program
 * Return: 0 if sucessful, otherwise 1
 */
int just_ls(char *pathname, int ac)
{
	DIR *dir;
	struct dirent *entry;
	struct stat name_info;

	if (lstat(pathname, &name_info) != 0)
		return (denied_access(pathname, ac));
	if (ac >= 2)
		printf("%s:\n", pathname);
	if (S_ISDIR(name_info.st_mode))
	{
		dir = opendir(pathname);
		if (dir == NULL)
			denied_access(pathname, ac);
		entry = readdir(dir);
		for (entry = readdir(dir); entry != NULL; entry = readdir(dir))
		{
			if (entry->d_name[0] != '.'  && entry->d_name[1] != '.')
				printf("%s", entry->d_name);
			if (entry != NULL) 
				printf("\t");
		}
		if (closedir(dir) != 0)
			major_trouble();
		return (0);
	}
	else if (S_ISREG(name_info.st_mode))
	{
		printf("%s", pathname);
		return (0);
	}
	return (1);
}
