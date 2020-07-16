#include "ls.h"
int main(int ac, char **av)
{
	int i;
	char *pathname, *options;

	if (ac == 1)
	{
		pathname = ".";
		just_ls(pathname, ac);
	}
	if (ac > 1)
	{
		options = checking_options(av);
		if (options == NULL)
		{
			for (i = 1; i < ac; i++)
			{
				just_ls(av[i], ac);
			}
			exit(EXIT_SUCCESS);
		}
		if (ac > 2)
			printf("mas de dos!");
		return (0);
	}
	return (1);
}
