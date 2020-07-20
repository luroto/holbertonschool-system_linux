#include "ls.h"
/**
 *printing_options - It handle some specific options for printing
 *@nodo: Pointer to the node to be printed
 *@options: selected options from av[i]
 *Return: 0
 */
int printing_options(const dfileinfo_t *nodo, char *options)
{
	int i;
	struct passwd *user;
	struct group *group;

	i = 0;

	user = getpwuid(nodo->user_id);
	group = getgrgid(nodo->group_id);

	if (_strchr(options, 'l') == 1 && _strchr(options, 'a') == 1)
	{
		printf((S_ISDIR(nodo->filemode)) ? "d" : "-");
		printf("%3o", nodo->filemode & 0777);
		printf(" %ld ", nodo->nhlks);
		printf(" %s", user->pw_name);
		printf(" %s", group->gr_name);
		printf(" %ld ", nodo->size);
		printf(" %s u", ctime(&nodo->mod_time.tv_sec));
		printf("%s\n", nodo->name);
		return (i);
	}
	if (_strchr(options, '1') == 1)
		printf("%s\n", nodo->name);
	return (i);
}
