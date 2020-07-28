#include "_getline.h"
/**
 *_getline - Implementation of getline function
 *@fd: File descriptor to be readed
 *Return: a string containing a line
 */
char *_getline(const int fd)
{
	static fdstring_t *head;
	fdstring_t *aux;
	int des, untnew;
	char *buffer, final[READ_SIZE];
	static char *another;

	printf("%d", fd);
	if (head != NULL && fd == -1)
	{
		free(another);
		free_fdstrings(&head);
		return (NULL);
	}
	buffer = malloc(sizeof(char));
	buffer = NULL;
	for (des = read(fd, final, READ_SIZE);
	     des != 0; des = read(fd, final, READ_SIZE))
	{
		if (buffer == NULL)
			buffer = strdup(final);
		else
			strcat(buffer, final);
	}
	untnew = counting_bytes(buffer);
	printf("%d", untnew);
	aux = add_fdstring(&head, fd, buffer);
	printf("%s", aux->string);
	another = strdup(aux->string);
	return (another);


}
/**
 *add_fdstring - Insert a node with a string
 *@h: structure of nodes
 *@fd: Node to be added
 *@buf: String to be added
 *Return: an fdstring node
 */
fdstring_t *add_fdstring(fdstring_t **h, int fd, char *buf)
{
	fdstring_t *newnodo, *aux;

	newnodo = malloc(sizeof(fdstring_t));
	if (newnodo == NULL)
		exit(EXIT_FAILURE);
	newnodo->fd = fd;
	newnodo->string = malloc(sizeof(char));
	if (newnodo == NULL)
		exit(EXIT_FAILURE);
	newnodo->string = strdup(buf);
	if ((*h) == NULL)
	{
		newnodo->next = NULL;
		*h = newnodo;
		return (newnodo);
	}
	if ((*h) != NULL)
	{
		aux = *h;
		while (aux->next != NULL)
		{
			if (aux->next->fd > newnodo->fd)
			{
				newnodo->next = aux->next->next;
				aux->next = newnodo;
				return (newnodo);
			}
		}
	}
	aux->next = newnodo;
	newnodo->next = NULL;
	return (newnodo);
}
/**
 *free_fdstrings - Free the linked list
 *@h: all the structure
 *Return: It's a void function
 */
void free_fdstrings(fdstring_t **h)
{
	fdstring_t *aux;

	while ((*h) != NULL)
	{
		aux = (*h)->next;
		free(*h);
		*h = aux;
	}
	*h = NULL;
}
/**
 *counting_bytes- Number of bytes until \n char
 *@buf: String to be checked
 *Return: Number of bytes before \n
 */
int counting_bytes(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '\n')
			return (i);
	}
	return (i)
}
