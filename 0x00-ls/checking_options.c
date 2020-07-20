#include "ls.h"
/**
 *checking_options - Ensures that the options only has the allowed ones
 *@arguments: the av[x] argument suspecte to hold the options
 *Return: the av[x] that contains the options
 */
char *checking_options(char **arguments)
{
	int i, j, k;
	char *options;

	options = "1aAlrStR";

	for (i = 1; arguments[i] != NULL; i++)
	{

		if (arguments[i][0] == '-')
		{
			for (j = 1; arguments[i][j] != '\0'; j++)
			{
				k = valid_options(options, arguments[i][j]);
				if (k != 1)
				{
					fprintf(stderr, "ls: the '%c' option is not valid\n", arguments[i][j]);
					exit(EXIT_FAILURE);
				}
			}
			return (arguments[i]);
		}
	}
	return (NULL);
}
