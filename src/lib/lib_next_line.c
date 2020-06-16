#include "cub3d.h"

void					lib_next_line(char **buff)
{
	while (**buff && **buff != '\n')
		(*buff)++;
	if (**buff)
		(*buff)++;
}