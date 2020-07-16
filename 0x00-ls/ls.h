#ifndef _LS_H_
#define _LS_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(int ac, char **av);
int just_ls(char *pathname, int ac);
char *checking_options(char **arguments);
int valid_options(char *array, char letter);
int _strchr(char *s, char c);
int denied_access(char *pathname, int ac);
void major_trouble(void);
int _strcmp(char *s1, char *s2);
#endif
