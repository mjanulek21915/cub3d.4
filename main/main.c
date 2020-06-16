#include "cub3d.h"

int				main(int ac, char **av)
{
	t_map *map;
	map = mk_map_cub(FILE_PATH);
	db_print_map(map);
}