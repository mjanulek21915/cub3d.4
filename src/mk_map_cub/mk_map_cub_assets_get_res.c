#include "cub3d.h"

void					mk_map_cub_assets_get_res(t_map *map, char **source, t_cub_assets *assets_checklist)
{
	if (assets_checklist->r == 1)
		lib_do_exit("duplicate asset : resolution\n");
	assets_checklist->r = 1;
	map->res_v = lib_get_value(source);
	if (**source == ' ')
		(*source)++;
	else
		lib_do_exit("invalid resolution format\n");
	map->res_h = lib_get_value(source);
	if (!(map->res_h) || !(map->res_v))
		lib_do_exit("invalid resolution values\n");
}