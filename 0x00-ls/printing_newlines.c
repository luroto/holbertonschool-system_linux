#include "ls.h"

void printing_newlines(dfileinfo_t *aux, char *options, int on)
{
	if (aux->next != NULL && on == 1 && _strchr(options, '1') == 1
	    && _strchr(options, 'a') == 0)
		printf("\n");
	if (aux->next != NULL && on == 1 && _strchr(options, 'a') == 1)
		printf("\n");
}