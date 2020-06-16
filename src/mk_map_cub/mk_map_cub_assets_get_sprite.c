#include "cub3d.h"

void					mk_map_cub_assets_get_sprite(t_map *map, char **source, t_cub_assets *assets_checklist)
{
	if (assets_checklist->s == 1)
		lib_do_exit("duplicate sprite\n");
	assets_checklist->s = 1;
	((t_sprite *)(map->assets['2'].data))->path = lib_get_path(source);
	((t_sprite *)(map->assets['2'].data))->texture = lib_get_texture(((t_sprite *)(map->assets['2'].data))->path);
}