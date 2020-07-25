#ifndef _LS_H_
#define _LS_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
/**
 *struct dfilelist_s - double linked list for readdir entries
 *@name: name of the entry
 *@filetype: filetype of the entry
 *@prev: pointer to the previous node
 *@next: pointer to the next node
 */
typedef struct dfilelist_s
{
	char *name;
	unsigned char filetype;
	struct dfilelist_s *prev;
	struct dfilelist_s *next;
} dfilelist_t;
/**
 *struct dfileinfo_s - single linked list for file data
 *@name: name of the entry
 *@filemode: type and mode for the entry (permissions)
 *@nhlks: Number of hard links
 *@user_id: User ID
 *@group_id: Group ID
 *@size: Size of the entry in bytes
 *@mod_time: Last time of modification
 *@prev: Pointer to the previous node
 *@next: Pointer to the next node
 *
 */
typedef struct dfileinfo_s
{
	char *name;
	mode_t filemode;
	nlink_t nhlks;
	uid_t user_id;
	gid_t group_id;
	off_t size;
	struct timespec mod_time;
	struct dfileinfo_s *next;
	struct dfileinfo_s *prev;
} dfileinfo_t;
int main(int ac, char **av);
char *checking_options(char **arguments);
char *checking_one_option(char **arg);
int valid_options(char *array, char letter);
int _strchr(char *s, char c);
int denied_access(char *pathname, int ac, int e);
void major_trouble(void);
int _strcmp(char *s1, char *s2);
dfilelist_t *addftend(dfilelist_t **h, char *n, char f);
void free_dfilelist(dfilelist_t *head);
void link_lists(dfilelist_t **a, dfilelist_t *b);
size_t print_filelist(const dfilelist_t *h);
char *_strdup(char *str);
void link_filedatas(dfileinfo_t **a, dfileinfo_t *b);
int getting_pathtype(int ac, char **av,  char *options);
int getting_info_dir(int ac, char *pathname, char *options);
dfileinfo_t *addfileinfo(dfileinfo_t **h, char *n, struct stat name_info);
int printing_nodes(const dfileinfo_t *h, char *options);
size_t print_fileinfo(const dfileinfo_t *h);
void free_fileinfo(dfileinfo_t *head);
int getting_stats(dfilelist_t *h, char *dph, char *options);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int printing_options(const dfileinfo_t *n, char *options);
int printing_other(const dfileinfo_t *n, char *options);
int printing_permissions(mode_t filemode);
int printing_time(const struct timespec time);
char *checking_more_options(int num, int len,  char **arg);
int number_of_options(int ac, char **av);
void printing_newlines(dfileinfo_t *aux, char *options, int on);
void newlines_between_types(int on, int fn, int dn, char *options);
#endif
