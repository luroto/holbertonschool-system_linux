#include "ls.h"
/**
 *print_fileinfo - Print a list of filenodos DLL
 *@h: Pointer to the first node of the list
 *Return: # of nodes
 */
size_t print_fileinfo(const dfileinfo_t *h)
{
	size_t contanodos = 0;

	if (h == NULL)
	{
		printf("Es nullito");
		return (contanodos);
	}
	else
	{
		while (h != NULL)
		{
			printf("%s: %d\n", h->name, h->filemode);
			h = h->next;
			contanodos++;
		}
	}
	return (contanodos);
}
