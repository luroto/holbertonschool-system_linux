#include "ls.h"
/**
 *addfileinfo -Function to collect the file info for each entry
 *in a double linked list
 *@h: Pointer to the double linked list of entries
 *@n: name of the entry
 *@name_info: stat structure with file info
 *Return: Pointer to the new node
 */
dfileinfo_t *addfileinfo(dfileinfo_t **h, char *n, struct stat name_info)
{
	dfileinfo_t *nuevonodo, *temp;

	nuevonodo = malloc(sizeof(dfileinfo_t));
	if (nuevonodo == NULL)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	nuevonodo->name = _strdup(n);
	nuevonodo->filemode = name_info.st_mode;
	nuevonodo->nhlks = name_info.st_nlink;
	nuevonodo->user_id = name_info.st_uid;
	nuevonodo->group_id = name_info.st_gid;
	nuevonodo->size = name_info.st_size;
	nuevonodo->mod_time = name_info.st_mtim;
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
