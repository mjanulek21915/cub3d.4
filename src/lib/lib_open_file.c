#include "cub3d.h"



char					*lib_open_file(char *path)
{
	int size;
	int fd;
	char *buff;

	if ((size = lib_get_file_len(path)) < 0)
		lib_do_exit("open_file get_len error\n");
	if (!(buff = malloc(sizeof(char) * (size + 1))))
		lib_do_exit("open_file buffer malloc error\n");
	buff[size] = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		lib_do_exit("open_file fd error\n");
	if ((read(fd, buff, size))	!= size)
		lib_do_exit("open_file buffer error\n");
	return (buff);
}