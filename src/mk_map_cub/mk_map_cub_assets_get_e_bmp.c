#include "cub3d.h"

void					mk_map_cub_assets_get_e_bmp(t_map *map, char **source, t_cub_assets *assets_checklist)
{
	if (assets_checklist->ea == 1)
		lib_do_exit("duplicate asset : E texture");
	assets_checklist->ea = 1;
	((t_block *)(map->assets['1'].data))->e_path = lib_get_path(source);
	((t_block *)(map->assets['1'].data))->e_texture = lib_get_texture(((t_block *)(map->assets['1'].data))->n_path);
}