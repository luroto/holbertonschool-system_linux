#include "ls.h"
/**
 *checking_one_option - Ensures that the options only has the allowed ones
 *@arg: the av[x] argument suspected to hold the options
 *Return: the av[x] that contains the options
 */
char *checking_one_option(char **arg)
{
	int i, j, k;
	char *opt;

	opt = "1aAlrStR";
	for (i = 1; arg[i] != NULL; i++)
	{
		if (arg[i][0] == '-' && _strcmp(arg[i], "-") != 0)
		{
			for (j = 1; arg[i][j] != '\0'; j++)
			{
				k = valid_options(opt, arg[i][j]);
				if (k != 1)
				{
					fprintf(stderr, "ls: the '%c' option is not valid\n",
						arg[i][j]);
					exit(EXIT_FAILURE);
				}
			}
			return (arg[i]);
		}
	}
	return (NULL);
}
