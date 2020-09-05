#include "readelf.h"
/**
 *main - main function for the 0-hreadelf
 *@argc: # of arguments
 *@argv: Array of arguments
 *Return: 1 in error, otherwise 0
 */
int main(int argc, char **argv)
{
	int op, flag, od;
	header_t *header;
	unsigned char class[9];
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./executable BINARYFILE\n", 31);
		return (1);
	}
	fd = fopen(argv[1], "rb");
	fread(&class, sizeof(char), 9, fd);
	fclose(fd);
	header = malloc(sizeof(header));
	od = open(argv[1, O_READONLY);
	if (class[4] == ELFCLASS64)
	{
		read(od, header.Elf64_Ehdr, 1);
		flag = 64;
	}
	if (class[4] == ELFCLASS32)
	{
		read(od, header.Elf32_Ehdr, 1);
		flag = 32;
	}
	close(od);
	printing_header(header, flag);
	return (0);
}
