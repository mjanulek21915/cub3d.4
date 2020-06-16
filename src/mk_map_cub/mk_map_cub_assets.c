#include "cub3d.h"




void					mk_map_cub_assets_checklist_init(t_cub_assets *checklist)
{
	checklist->r = 0;
	checklist->no = 0;
	checklist->so = 0;
	checklist->we = 0;
	checklist->ea = 0;
	checklist->s = 0;
	checklist->f = 0;
	checklist->c = 0;
}

int static				mk_map_cub_assets_checklist_check(t_cub_assets *checklist)
{
	if (checklist->r == 1 && 
	checklist->no == 1 && 
	checklist->so == 1 && 
	checklist->we == 1 && 
	checklist->ea == 1 && 
	checklist->s == 1 && 
	checklist->f == 1 && 
	checklist->c == 1)
		return (1);
	return (0);
}
void					mk_map_cub_assets(t_map *map)
{
	t_cub_assets assets_checklist;
	int rst;

	rst = 0;
	if (!(map->assets['1'].data = malloc(sizeof(t_block))))
		lib_do_exit("mk_map_cub_assets block malloc fail");
	if (!(map->assets['2'].data = malloc(sizeof(t_sprite))))
		lib_do_exit("mk_map_cub_assets sprite malloc fail");
	mk_map_cub_assets_checklist_init(&assets_checklist);
	while (*(map->file_ptr) && !(rst = mk_map_cub_assets_checklist_check(&assets_checklist)))
	{
		while (*(map->file_ptr) == '\n')
			(map->file_ptr)++;
		if (lib_iz_it("R ", &(map->file_ptr)))
			mk_map_cub_assets_get_res(map, &(map->file_ptr), &assets_checklist);
		else if (lib_iz_it("NO ", &(map->file_ptr)))
			mk_map_cub_assets_get_n_bmp(map, &(map->file_ptr), &assets_checklist);
		else if (lib_iz_it("SO ", &(map->file_ptr)))
			mk_map_cub_assets_get_s_bmp(map, &(map->file_ptr), &assets_checklist);
		else if (lib_iz_it("WE ", &(map->file_ptr)))
			mk_map_cub_assets_get_w_bmp(map, &(map->file_ptr), &assets_checklist);
		else if (lib_iz_it("EA ", &(map->file_ptr)))
			mk_map_cub_assets_get_e_bmp(map, &(map->file_ptr), &assets_checklist);
		else if (lib_iz_it("S ", &(map->file_ptr)))
			mk_map_cub_assets_get_sprite(map, &(map->file_ptr), &assets_checklist);
		else if (lib_iz_it("F ", &(map->file_ptr)))
			mk_map_cub_assets_get_floor(map, &(map->file_ptr), &assets_checklist);
		else if (lib_iz_it("C ", &(map->file_ptr)))
			mk_map_cub_assets_get_ceiling(map, &(map->file_ptr), &assets_checklist);
		else
			lib_do_exit("mk_map_cub_assets source map : character out of place");
	}
	if (rst == 0)
		lib_do_exit("mk_map_cub_assets error");
}