#include "ls.h"
/**
 **_strdup - copies a string on a newly allocated space
 *
 *@str: source string
 *
 *Return: It returns a pointer to the allocated memory
 */
char *_strdup(char *str)
{
	int cont, contn;
	char *nws;

	if (str == NULL)
	{
		return (NULL);
	}
	for (cont = 0; str[cont]; cont++)
	{
	}
	nws = malloc(sizeof(*nws) * cont + 1);
	if (nws == NULL)
	{
		free(nws);
		return (NULL);
	}
	for (contn = 0; str[contn]; contn++)
	{
		nws[contn] = str[contn];
	}
	nws[contn] = 0;
	return (nws);
}
