#include "ls.h"
/**
 *_strcmp - compares two strings lexicographically
 *
 *@s1: first source
 *@s2: second source
 *
 *Return: it depends on the result, 0 if they are equal, otherwise it prints
 *a subtraction
 */
int _strcmp(char *s1, char *s2)
{
	int iterador = 0, iteras1 = 1, igualdad;

	while (s1[iteras1])
	{
		iteras1++;
	}
	while (iterador <= iteras1)
	{
		if (s1[iterador] != s2[iterador])
		{
			igualdad = s1[iterador] - s2[iterador];
			break;
		}
		else
		{
			igualdad = 0;
		}
		iterador++;
	}
		return (igualdad);
}
