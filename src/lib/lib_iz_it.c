#include "cub3d.h"

int						lib_iz_it(char *needle, char **haystack)
{
	char *temp;
	temp = *haystack;

	while (*temp && *needle == *temp)
	{
		needle++;
		temp++;
	}
	if (!(*needle))
	{
		*haystack = temp;
		return (1);
	}
	return (0);
}
