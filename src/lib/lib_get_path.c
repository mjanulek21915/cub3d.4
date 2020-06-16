#include "cub3d.h"

int						lib_get_path_strlen(char *buff)
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

void					lib_get_path_strncpy(char **src, char *dest, int len)
{
	while (len--)
		*dest++ = *((*src)++);
	*dest = 0;
}

char					*lib_get_path(char **src)
{
	char *rst;
	int len;

	len = lib_get_path_strlen(*src);
	if (!(rst = malloc(sizeof(char) * (len + 1))))
		lib_do_exit("get_path malloc fail");
	lib_get_path_strncpy(src, rst, len);
	return (rst);
}