#include "ls.h"
/**
 *checking_more_options - concatenates all the arguments
 *@num: total of arguments
 *@len: total lenght of all arguments which start at '-'
 *@arg: the av[x] argument suspected to hold the options
 *Return: the av[x] that contains the options
 */
char *checking_more_options(int num, int len, char **arg)
{
	int i, j, k;
	char *opt, *all;

	all = malloc(len + num);
	_strcpy(all, "");
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
					free(all);
					exit(EXIT_FAILURE);
				}
			}
			_strcat(all, arg[i]);
			}
	}
	return (all);
}
