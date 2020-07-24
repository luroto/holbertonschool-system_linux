#include "ls.h"
/**
 *number_of_options - returns the number of options for the ls function
 *@ac: Numbrer of arguments
 *@av: array of arguments
 *Return: total of options for ls program
 */
int number_of_options(int ac, char **av)
{
	int i, total = 0;

	for (i = 1; i < ac; i++)
	{
		if (av[i][0] == '-')
			total++;
	}
	return (total);
}
