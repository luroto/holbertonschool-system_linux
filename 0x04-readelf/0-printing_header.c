#include "readelf.h"
/**
 *printing_header - Main function for printing headers
 *@header: Structure to be printed
 *@flag: Architecture of the file
 */
void printing_header(header_t *header, int flag)
{
	print_ei_ident(header, flag);
	print_e_type(header, flag);
	print_e_machine(header, flag);
	print_e_version(header, flag);
	print_e_entry(header, flag);
	print_e_phoff(header, flag);
	print_esloff(header, flag);
	print_e_flags(header, flag);
	print_e_hsize(header, flag);
	print_e_phentsize(header, flag);
	print_e_phnum(header, flag);
	print_e_shentsize(header, flag);
	print_e_shnum(header, flag);
}
/**
 *print_ei_ident - Function for printing the first 9 bytes of the header
 *@header: Structure that holds the data
 *@flag: Architecture of the binary file
 */
void print_ei_ident(header_t *header, int flag)
{
	int i = 0;

	if (flag == 64)
	{
		while (i < EI_NIDENT)
		{
			printf("%d ", header.h64.e_ident[i]);
			i++;
		}
	}
}
/**
 *print_e_type - Print the type of a machine
 *@header : Structure that holds the data
 *
 *
 */
