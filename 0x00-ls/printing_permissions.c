#include "ls.h"
/**
 *printing_permissions - For printing permissions for files
 *@filemode: Info about the file
 *Return: 0
 */
int printing_permissions(mode_t filemode)
{

	printf((S_IRUSR & filemode) ? "r" : "-");
	printf((S_IWUSR & filemode) ? "w" : "-");
	printf((S_IXUSR & filemode) ? "x" : "-");
	printf((S_IRGRP & filemode) ? "r" : "-");
	printf((S_IWGRP & filemode) ? "w" : "-");
	printf((S_IXGRP & filemode) ? "x" : "-");
	printf((S_IROTH & filemode) ? "r" : "-");
	printf((S_IWOTH & filemode) ? "w" : "-");
	printf((S_IXOTH & filemode) ? "x" : "-");

	return (0);
}
