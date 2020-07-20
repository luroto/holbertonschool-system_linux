#include "ls.h"
/**
 *print_filelist - Print a readdir entries DLL
 *@h: Pointer to the first node of the DLL
 *Return: # of printed nodes
 */
size_t print_filelist(const dfilelist_t *h)
{
	size_t contanodos = 0;

	if (h == NULL)
	{
		return (contanodos);
	}
	else
	{
		while (h != NULL)
		{
			printf("%s: %d\n", h->name, h->filetype);
			h = h->next;
			contanodos++;
		}
	}
	return (contanodos);
}
