#include "ls.h"
/**
 **_strcpy - copies the string pointed to by src, including the \0 byte to dest
 *@dest: Pointer to a string which receives
 *@src: Source string
 *Return: Pointer to the destination string
 */

char *_strcpy(char *dest, char *src)
{
	int itera;

	for (itera = 0; src[itera] != '\0'; itera++)
	{
		dest[itera] = src[itera];
	}
	dest[itera] = '\0';
	return (dest);
}
