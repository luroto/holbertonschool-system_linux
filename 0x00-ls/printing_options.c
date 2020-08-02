#include "ls.h"
/**
 *printing_options - It handle some specific options for printing
 *@n: Pointer to the node to be printed
 *@options: selected options from av[i]
 *Return: 0
 */
int printing_options(const dfileinfo_t *n, char *options)
{
	struct passwd *user;
	struct group *group;

	user = getpwuid(n->user_id);
	group = getgrgid(n->group_id);

	if (_strchr(options, 'l') == 0 && _strchr(options, '1') == 0)
	{
		printf("%s", n->name);
		if (n->next != NULL)
			printf("  ");
	}
	if (_strchr(options, 'l') == 1)
	{
		printf((S_ISDIR(n->filemode)) ? "d" : "-");
		printing_permissions(n->filemode);
		printf(" %ld", n->nhlks);
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
