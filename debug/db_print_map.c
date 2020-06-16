#include "cub3d.h"

void		db_print_map(t_map *map)
{
	int x;
	int y;
	int border;

	x = 0;
	border = -2;

	fprintf(stderr, "db_print_map:\n size_x = %d\n size_y = %d\n\n floor = %x\n ceiling = %x\n\n", map->size_x, map->size_y, map->floor, map->ceiling);
	fprintf(stderr, " res_v = %f\n res_h = %f\n\n pos_x = %f\n pos_y = %f\n azi =%f\n\n", map->res_v, map->res_h, map->pos_x, map->pos_y, map->azi);
	while (border++ < map->size_y)
		fprintf(stderr, "-");
	border = -2;
	fprintf(stderr, "\n");
	while (x < map->size_x)
	{
		y = 0;
		fprintf(stderr, "|");
		while (y < map->size_y)
		{
			if (map->walls[x][y])
				fprintf(stderr, "x");
			else
				fprintf(stderr, " ");
			y++;
		}
		fprintf(stderr, "|\n");
		x++;
	}
	while (border++ < map->size_y)
		fprintf(stderr, "-");
	fprintf(stderr, "\n");

}