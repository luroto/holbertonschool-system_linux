#include "ls.h"

/**
 *main - The main handler for my custom ls function
 *@ac: number of arguments received
 *@av: pointer to the arguments from the command line
 *Return: 0 if sucessful, otherwise 1
 */
int main(int ac, char **av)
{
	char *options;

	if (ac == 1)
	{
		options = NULL;
		getting_info_dir(ac, ".", options);
		return (0);
	}
	if (ac > 1)
	{
		options = checking_options(av);
		if (ac == 2 && options != NULL)
			getting_info_dir(ac, ".", options);
		else
			getting_pathtype(ac, av, options);
		return (0);
	}
	return (1);
}
