#ifndef READELF_H_
#define READELF_H_
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/**
 *struct header_s - structure for holding header data
 *@h32: header structure for the 32 architecture
 *@h64: header structure for the 64 architecture
 */
typedef struct header_s
{
	Elf32_Ehdr *h32;
	Elf64_Ehdr *h64;
} header_t;
/**
 *struct program_s- Structure for holding program data
 *@p32: Structure for 32 architecture
 *@p64: Structure for 64 architecture
 *
 */
typedef struct program_s
{
	Elf32_Phdr *p32;
	Elf64_Phdr *p64;
} program_t;
/**
 *struct section_s- Structure for holding section data
 *@s32: Structure for 32bits architecture
 *@s64: Structure for 64 bit architecture
 *
 */
typedef struct section_s
{
	Elf32_Shdr *s32;
	Elf64_Shdr *s64;
} section_t;
int main(int argc, char **argv);
void printing_header(void *header, int flag);
#endif
