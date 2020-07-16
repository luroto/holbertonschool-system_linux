#include "ls.h"
/**
 **_strchr - locates a character in a string
 *
 *@s: pointer of source
 *@c: character to be locate
 *
 *Return: 1 if the char is founded at least once, otherwise 0 
 */
int _strchr(char *s, char c)
{
	while (s[0])
	{
		if (s[0] == c)
		{
			return (1);
		}
		s++;
	}
	if (s[0] == c)
	{
		return (1);
	}
	return (0);
}
