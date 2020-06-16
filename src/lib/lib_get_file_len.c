#include "cub3d.h"

int						lib_get_file_len(char *path)
{
	int fd;
	int rst;
	char buff;

	rst = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		lib_do_exit("open_file_get_len fd error\n");
	while (read(fd, &buff, 1))
		rst ++;
	close(fd);
	return (rst);	
}