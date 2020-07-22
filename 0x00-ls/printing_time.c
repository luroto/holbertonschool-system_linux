#include "ls.h"
/**
 *printing_time - Function to format the ctime printing time
 *resulting string
 *@time: Timespec structure
 *Return: 1
 */
int printing_time(const struct timespec time)
{
	char date[14];
	char *full;
	int i, j;

	full = _strdup(ctime(&time.tv_sec));
	i = 0;
	j = 0;
	for (i = 4; i < 16; i++)
	{
		if (full[i] == '\n')
			date[j] = ' ';
		date[j] = full[i];
		j++;
	}
	date[j] = ' ';
	date[j + 1] = '\0';
	printf("%s", date);
	free(full);
	return (1);
}
