#include "ls.h"
/**
 *valid_options : Checks if all the options in the '-' argument are valid
 *@array: Array that contains the allowed options
 *@letter: Letter to be found
 *Return: 1 if found, otherwise 0
 *
 */
int valid_options(char *array, char letter)
{
	while (array[0])
	{
		if (array[0] == letter)
		{
			return (1);
		}
		array++;
	}
	if (array[0] == letter)
		return (1);
	return (0);
}
