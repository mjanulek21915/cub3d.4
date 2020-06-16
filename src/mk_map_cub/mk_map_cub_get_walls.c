#include "cub3d.h"

int	static				mk_map_cub_get_walls_x_size(char *buff)
{
	int size;

	while (*buff && *buff == '\n')
		buff++;
	size = 0;
	while (*buff && *buff != '\n')
	{
		size++;
		lib_next_line(&buff);
	}
	return (size);
}

int	static				mk_map_cub_get_walls_y_size(char *buff)
{
	int size;
	int max_size;

	size = 0;
	max_size = 0;
	while (*buff && *buff == '\n')
		buff++;
	while (*buff && *buff != '\n' )
	{
		while (*buff && *buff != '\n')
		{
			size++;
			buff++;
		}
		if (size > max_size)
			max_size = size;
		size = 0;
		if (*buff == '\n')
			*buff++;
	}
	return (max_size);
}

void static				mk_map_cub_get_walls_malloc(t_map *map, char *buff)
{
	int x;
	int y;

	x = 0;
	y = 0;
	map->size_x = mk_map_cub_get_walls_x_size(buff);
	map->size_y = mk_map_cub_get_walls_y_size(buff);
	if (!(map->walls = malloc(sizeof(t_block **) * map->size_x)))
		lib_do_exit("mk_map_wall malloc x fail\n");
	while (x < map->size_x)
	{
		if (!(map->walls[x] = malloc(sizeof(t_block *) * map->size_y)))
			lib_do_exit("mk_map_wall malloc y fail\n");
		while (y < map->size_y) 
		{
			map->walls[x][y] = NULL;
			y++;
		}
		y = 0;
		x++;
	}
}

void static				mk_map_cub_mk_walls(t_map *map, char *source)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (*source && !(lib_iz_it("\n\n", &source)))
	{
		if (*source == '\n')
		{
			y = -1;
			x++;
		}
		else if(*source == '1')
		{
			map->walls[x][y] = (t_block *)(map->assets['1'].data);
		}
		source++;
		y++;
	}
}

void					mk_map_cub_get_walls(t_map *map)
{	
	mk_map_cub_get_walls_malloc(map, map->file_ptr);
	mk_map_cub_mk_walls(map, map->file_ptr);
}