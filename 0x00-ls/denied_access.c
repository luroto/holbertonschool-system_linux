#include "ls.h"
/**
 *denied_access - generic error message
 *@pathname: The pathname that wasn't found
 *@ac : number of arguments on the original program
 *Return: 0 
 */

int denied_access(char *pathname, int ac)
{
	fprintf(stderr,"hls: cannot access '%s': ", pathname);
	perror("");
	if (ac == 2)
		exit(EXIT_FAILURE);
	return (0);
}
