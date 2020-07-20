#include "ls.h"
/**
 *addftend - Add a list of entries from readdir to a double linked list
 *@h: the entire double linked list
 *@n: name of the entry
 *@f: filetype of the entry
 *Return: the new node
 */
dfilelist_t *addftend(dfilelist_t **h, char *n, char f)
{
	dfilelist_t *nuevonodo, *temp;

	nuevonodo = malloc(sizeof(dfilelist_t));
	if (nuevonodo == NULL)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	nuevonodo->name = _strdup(n);
	nuevonodo->filetype = f;
	nuevonodo->next = NULL;
	if (*h == NULL)
	{
		nuevonodo->prev = NULL;
		*h = nuevonodo;
		return (nuevonodo);
	}
	temp = *h;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = nuevonodo;
	nuevonodo->prev = temp;
	return (nuevonodo);
}
