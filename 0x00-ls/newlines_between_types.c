#include "ls.h"
/**
 *newlines_between_types - printing newlines according to options
 *@on: options!= NULL
 *@fn: files != NULL
 *@dn: dirs != NULL
 *@options: All the options sent in the commandline
 */
void newlines_between_types(int on, int fn, int dn, char *options)
{
	if (on == 1 && _strchr(options, 'a') == 1 && _strchr(options, '1') == 0
	    && fn == 1)
		printf("\n");
	if (on == 1 && _strchr(options, 'A') == 1 && _strchr(options, '1') == 0
	    && fn == 1)
		printf("\n");
	if (fn == 1 && dn == 1)
		printf("\n");
}
