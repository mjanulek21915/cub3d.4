#include "cub3d.h"

static t_map			*mk_map_cub_malloc(void)
{
	t_map *map;
	if (!(map = malloc(sizeof(t_map))) || !(map->assets = malloc(sizeof(t_asset) * 128)))
		lib_do_exit("mk_map_malloc fail");
	return(map);
}

static void					mk_map_cub_get_player(t_map *map, char *source)
{
	int offset;
	offset = 0;
	int x;
	int y;

	x = 0;
	y = 0;
	while (*source && (*source == ' ' || *source == '0'|| *source == '1'|| *source == '2' || *source == '\n'))
	{
		y++;
		if (*source == '\n')
		{
			y = 0;
			x++;
		}
		source++;
	}
fprintf(stderr, "offset = %d\n", offset);
	if (*source == 'N')
		map->azi = 270;
	else if (*source == 'S')
		map->azi = 90;
	else if (*source == 'E')
		map->azi = 0;
	else if (*source == 'W')
		map->azi = 180;
	else
		lib_do_exit("mk_map_cub_get_player error\n");
	map->pos_x = x;
	map->pos_y = y;
}

t_map					*mk_map_cub(char *path)
{
	t_map *map;
	map = mk_map_cub_malloc();
	map->file_buffer = lib_open_file(path);
	map->file_ptr = map->file_buffer;
	mk_map_cub_assets(map);
	while (*(map->file_ptr) == '\n')
		map->file_ptr++;
	mk_map_cub_get_walls(map);
	mk_map_cub_get_player(map, map->file_ptr);
	return (map);
}