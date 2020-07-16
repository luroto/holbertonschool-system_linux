#include "ls.h"

int just_ls(char *pathname, char *options)
{
	DIR *dir;
	struct dirent *entry;
	struct stat name_info;
//	int print_hidden, print_A, print_1, print_L;

//	print_hidden = 0;
//	print_A = 0;
//	print_1 = 0;
//	print_L = 0;
	printf("%s: %s\n", "This is the path which arrive",pathname);
	if (lstat(pathname, &name_info) != 0)
	{
		perror("");
		return (0);
	}
//	if (options != NULL)
//	{
//		print_hidden = _strchr(options, 'a');
//		print_A = _strchr(options, 'A');
//		print_1 = _strchr(options, '1');
//		print_L = _strchr(options, 'l');
//	}
	if (S_ISDIR(name_info.st_mode))
	{
		if ((dir = opendir(pathname)) == NULL)
		{
			fprintf(stderr, "hls: cannot access %s: ", pathname);
			perror("");
			exit(EXIT_FAILURE);
		}
		while ((entry = readdir(dir)) != NULL)
		{
			if (options != NULL)
			{
				continue;
			}
			else
			{
				if (entry->d_name[0] != '.' && entry->d_name[1] != '.')
					printf("%s", entry->d_name);
				printf("\t");
			}
     		}
		if (closedir(dir) != 0)
		{
			perror("");
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	else if (S_ISREG(name_info.st_mode))
	{
		printf("%s", pathname);
		return(0);
	}
	else if (S_ISLNK(name_info.st_mode))
	{
		printf("What do i Need with symlink?\n");
		return(0);
	}
	else
	{
		printf("El horror");
		return(-1);
	}
}
