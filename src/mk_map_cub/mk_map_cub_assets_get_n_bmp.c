#include "cub3d.h"

void					mk_map_cub_assets_get_n_bmp(t_map *map, char **source, t_cub_assets *assets_checklist)
{
	if (assets_checklist->no == 1)
		lib_do_exit("duplicate asset : N texture");
	assets_checklist->no = 1;
	((t_block *)(map->assets['1'].data))->n_path = lib_get_path(source);
	((t_block *)(map->assets['1'].data))->n_texture = lib_get_texture(((t_block *)(map->assets['1'].data))->n_path);
}