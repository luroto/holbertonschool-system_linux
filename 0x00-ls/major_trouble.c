#include "ls.h"
/**
 *major_trouble - Catch a major error in the system
 *Return: Void function, it will make an EXIT FAILURE
 */
void major_trouble(void)
{
	fprintf(stderr, "hls: Error: ");
	perror("");
	exit(EXIT_FAILURE);
}
