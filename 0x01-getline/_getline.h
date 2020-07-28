#ifndef __GETLINE_H_
#define __GETLINE_H_
#define READ_SIZE 1024
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 *struct fdstring_s - single linked list for cars info
 *@fd: name of the entry
 *@string: type and mode for the entry (permissions)
 *@next: Pointer to the next node
 */
typedef struct fdstring_s
{
	int fd;
	char *string;
	struct fdstring_s *next;
} fdstring_t;
int counting_bytes(char *buf);
char *_getline(const int fd);
void free_fdstrings(fdstring_t **h);
fdstring_t *add_fdstring(fdstring_t **h, int fd, char *buffer);
#endif
