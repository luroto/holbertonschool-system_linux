#include "ls.h"
/**
 *_strcat - concatenates two strings
 *
 *@dest: string which receives
 *
 *@src: source string which will be used as appendix
 *
 *Return: It's supposed to be the dest pointer
 */
char *_strcat(char *dest, char *src)
{
	int idest = 0, isrc = 0, totalsrc = 0;

	while (dest[idest])
		idest++;
	while (src[isrc])
		isrc++;
	while (totalsrc <= isrc)
	{
		dest[idest + totalsrc] = src[totalsrc];
		totalsrc++;
	}
	dest[idest + totalsrc] = 0;
	return (dest);
}
