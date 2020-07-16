#include "ls.h"
int main(int ac, char **av)
{
//	int i;
	char *pathname, *options;

	if (ac == 1)
	{
		pathname = ".";
		options = NULL;
		just_ls(pathname,options);
	}
	if (ac > 1)
	{
		options = checking_options(av);
		if (ac == 2)
		{
			if (options != NULL)
				pathname = ".";
			else
				pathname = av[1];
			just_ls(pathname,options);
		}
		if (ac > 2)
			printf("mas de dos!");
	}
	return (1);
}
