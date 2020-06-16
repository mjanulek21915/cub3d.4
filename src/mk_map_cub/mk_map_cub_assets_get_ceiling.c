#include "cub3d.h"

void					mk_map_cub_assets_get_ceiling(t_map *map, char **source, t_cub_assets *assets_checklist)
{
	t_pixel pix;
	pix.argb[0] = 0;

	if (assets_checklist->c == 1)
		lib_do_exit("duplicate ceiling value \n");
	assets_checklist->c = 1;
	if (**source < '0' || **source > '9')
		lib_do_exit("invalid ceiling format\n");
	pix.argb[1] = (char)lib_get_value(source);
	if (**source == ',')
		(*source)++;
	else
		lib_do_exit("invalid ceiling format\n");
	if (**source < '0' || **source > '9')
		lib_do_exit("invalid ceiling format\n");
	pix.argb[2] = (char)lib_get_value(source);
	if (**source == ',')
		(*source)++;
	else
		lib_do_exit("invalid ceiling format\n");
	if (**source < '0' || **source > '9')
		lib_do_exit("invalid ceiling format\n");
	pix.argb[3] = (char)lib_get_value(source);
	if (**source != '\n')
		lib_do_exit("invalid ceiling format");
	map->ceiling = pix.color;
}