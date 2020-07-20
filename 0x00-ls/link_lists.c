#include "ls.h"
/**
 *link_lists - Concatenates the files entries list with the directories entries
 * list
 *@a: Pointer to the entire files doubly linked list
 *@b: Pointer to the first node
 *Return: Void function
 */
void link_lists(dfilelist_t **a, dfilelist_t *b)
{
	dfilelist_t *aux, *head;

	aux = *a;
	head = b;

	while (aux->next != NULL)
		aux = aux->next;
	head->prev = aux;
	aux->next = head;
}
