#include "cub3d.h"

void					mk_map_cub_assets_get_floor(t_map *map, char **source, t_cub_assets *assets_checklist)
{
	t_pixel pix;
	pix.argb[0] = 0;

	if (assets_checklist->f == 1)
		lib_do_exit("duplicate floor value \n");
	assets_checklist->f = 1;
	if (**source < '0' || **source > '9')
		lib_do_exit("invalid floor format\n");
	pix.argb[1] = (char)lib_get_value(source);
	if (**source == ',')
		(*source)++;
	else
		lib_do_exit("invalid floor format\n");
	if (**source < '0' || **source > '9')
		lib_do_exit("invalid floor format\n");
	pix.argb[2] = (char)lib_get_value(source);
	if (**source == ',')
		(*source)++;
	else
		lib_do_exit("invalid floor format\n");
	if (**source < '0' || **source > '9')
		lib_do_exit("invalid floor format\n");
	pix.argb[3] = (char)lib_get_value(source);
	if (**source != '\n')
		lib_do_exit("invalid floor format");
	map->floor = pix.color;
}