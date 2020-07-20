#include "ls.h"
/**
 *link_filedatas - Concatenates two doubly linked list of filedata
 *@a: The doubly linked list for the files DLL
 *@b: the first node of the dirs DLL
 *Return: It's a void function
 */
void link_filedatas(dfileinfo_t **a, dfileinfo_t *b)
{
	dfileinfo_t *aux, *head;

	aux = *a;
	head = b;

	while (aux->next != NULL)
		aux = aux->next;
	head->prev = aux;
	aux->next = head;
}
