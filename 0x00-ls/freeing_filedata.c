#include "ls.h"
/**
 *free_fileinfo - frees a doubly linked list of some dir entries' data
 *@head: Pointer to the first node
 *Return: Nothing, void function
 */
void free_fileinfo(dfileinfo_t *head)
{
	dfileinfo_t *aux;

	while (head != NULL)
	{
		aux = head->next;
		free(head->name);
		free(head);
		head = aux;
	}
}
