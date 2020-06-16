#include "cub3d.h"

int						lib_strlen(char *buff)
{
	int i;

	i  = 0;
	while(*buff != '\n' && *buff)
	{
		*buff++;
		i++;
	}
	return (i);
}