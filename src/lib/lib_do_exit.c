#include "cub3d.h"

void					lib_do_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}