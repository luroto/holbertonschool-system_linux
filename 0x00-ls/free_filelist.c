#include "ls.h"
/**
 *free_dfilelist - Free a doubly linked list of entries from readdir
 *@head: Pointer to the first node of the linked list
 *Return: Nothing, void function
 */


void free_dfilelist(dfilelist_t *head)
{
	dfilelist_t *aux;

	while (head != NULL)
	{
		aux = head->next;
		free(head->name);
		free(head);
		head = aux;
	}
}
