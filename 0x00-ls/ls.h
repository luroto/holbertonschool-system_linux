#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(int ac, char **av);
int just_ls(char *pathname, char *options);
char *checking_options(char **arguments);
int valid_options(char *array, char letter);
//stat_t *whatisit(char *pathname);
int _strchr(char *s, char c);
