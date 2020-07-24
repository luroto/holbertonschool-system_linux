#include "ls.h"
/**
 *printing_other - It handle some specific options for printing all but hidden
 *files
 *@n: Pointer to the node to be printed
 *@options: selected options from av[i]
 *Return: 0
 */
int printing_other(const dfileinfo_t *n, char *options)
{
	struct passwd *user;
	struct group *group;
	int oc = (n->name[0] == '.' && _strlen(n->name) == 1);
	int occ = (n->name[0] == '.' && n->name[1] == '.'  &&
		   _strlen(n->name) == 2);

	user = getpwuid(n->user_id);
	group = getgrgid(n->group_id);
	if (_strchr(options, 'a' == 0))
	{
		if ((n->name[0] == '.' && _strlen(n->name) == 1) ||
		    (n->name[0] == '.' && n->name[1] == '.'))
			return (1);
	}
	if ((_strchr(options, 'A') == 1) && (S_ISDIR(n->filemode)))
	{
		if (oc == 1 || occ == 1)
			return (1);
	}
	if (_strchr(options, 'l') == 0 && _strchr(options, '1') == 0)
		printf("%s  ", n->name);
	if (_strchr(options, 'l') == 1)
	{
		printf((S_ISDIR(n->filemode)) ? "d" : "-");
		printing_permissions(n->filemode);
		printf(" %ld ", n->nhlks);
		printf(" %s", user->pw_name);
		printf(" %s", group->gr_name);
		printf(" %ld ", n->size);
		printing_time(n->mod_time);
		printf("%s\n", n->name);
	}
	if (_strchr(options, '1') == 1 && _strchr(options, 'l') == 0)
		printf("%s\n", n->name);
	return (1);
}
