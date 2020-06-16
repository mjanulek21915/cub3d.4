#include "cub3d.h"

float					lib_get_value(char **buff)
{
	float rst;
	float div;

	rst = 0;
	div = 10;
	while (**buff >= '0' && **buff <= '9')
	{
		rst = (rst * 10) + **buff - '0';
		(*buff)++;
	}
	if (**buff == '.')
	{
		(*buff)++;
		while (**buff >= '0' && **buff <= '9')
		{
			rst = rst + ((**buff - '0') / div);
			div = div * 10;
			(*buff)++;
		}
	}
	return (rst);
}