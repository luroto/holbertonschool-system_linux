#include "ls.h"
/**
 *checking_options - Ensures that the options only has the allowed ones
 *@arguments: the av[x] argument suspecte to hold the options
 *Return: the av[x] that contains the options
 */
char *checking_options(char **arguments)
{
	int i, cou, len;

	cou = 0;
	len = 0;

	for (i = 1; arguments[i] != NULL; i++)
		if (arguments[i][0] == '-')
		{
			cou++;
			len += _strlen(arguments[i]);
		}
	if (cou == 0)
		return (NULL);
	if (cou == 1)
		return (checking_one_option(arguments));
	if (cou > 1)
		return (checking_more_options(cou, len, arguments));
	return (NULL);
}
