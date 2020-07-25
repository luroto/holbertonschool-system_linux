#include "ls.h"
/**
 *printing_nodes - Function that prints with the options format
 *@h: Pointer to the first node of the filedata DLL
 *@options: av[x] which contains the options
 *Return: 0
 */
int printing_nodes(const dfileinfo_t *h, char *options)
{
	if (options == NULL)
	{
		while (h != NULL)
		{
			if ((h->name[0] != '.') ||
			    (h->name[0] != '.' && h->name[1] != '.'))
				printf("%s", h->name);
			if (h->next != NULL &&
			    ((h->name[0] != '.' ||
			      (h->name[0] != '.' && h->name[1] != '.'))))
				printf("  ");
			if (h->next == NULL && h->name[0] != '.')
				printf("\n");
			h = h->next;
		}
		return (0);
	}
	while (h != NULL)
	{
		if (_strchr(options, 'a') == 1)
			printing_options(h, options);
		else
			printing_other(h, options);
		h = h->next;
	}
	return (0);
}
