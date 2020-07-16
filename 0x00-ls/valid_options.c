#include "ls.h"

int valid_options(char *array, char letter)
{
	while (array[0])
	{
		if (array[0] == letter)
		{
			return (0);
		}
		array++;
	}
	if (array[0] == letter)
		return (0);
	return (1);
}
