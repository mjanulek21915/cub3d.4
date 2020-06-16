#ifndef __CUBD_H__
#define __CUBD_H__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

#define FILE_PATH "/home/aaa/cub3d_4/maps/map_test"




struct						s_texture;
typedef struct s_texture	t_texture;

struct						s_block;
typedef struct s_block		t_block;

struct						s_asset;
typedef struct s_asset		t_asset;

struct						s_map;
typedef struct s_map		t_map;

struct						s_sprite;
typedef struct s_sprite		t_sprite;

union						u_pixel;
typedef union u_pixel		t_pixel;


struct			s_texture
{
	int **bitmap;
	int size;
	int size_v;
	int size_h;
};



struct			s_block
{
	int is_void;

	char *n_path;
	t_texture *n_texture;

	char *s_path;
	t_texture *s_texture;

	char *e_path;
	t_texture *e_texture;

	char *w_path; 
	t_texture *w_texture;
};

struct	s_sprite
{
	char *path;
	t_texture *texture;
	float pos_x;
	float pos_y;
};



struct			s_asset
{
	char type;
	void *data;
};



union			u_pixel
{
	char argb[4];
	int color;
};



struct			s_map
{

	float res_v;
	float res_h;

	int size_x;
	int size_y;

	float fov_v;
	float fov_h;

	float spd_p;
	float spd_r;

	float pos_x;
	float pos_y;

	float azi;
	float ati;

	float *mask_v;
	float *mask_h;

	int floor;
	int ceiling;

	char *file_buffer;
	char *file_ptr;
	char *map_ptr;
	t_asset *assets;
	t_block ***walls;
};



typedef struct	s_cub_assets
{
	int r;
	int no;
	int so;
	int we;
	int ea;
	int s;
	int f;
	int c;

}				t_cub_assets;


void		db_print_map(t_map *map);



char					*lib_open_file(char *path);
int						lib_iz_it(char *needle, char **haystack);
void					lib_do_exit(char *msg);
int						lib_get_file_len(char *path);
float					lib_get_value(char **buff);
char					*lib_get_path(char **src);
t_texture				*lib_get_texture(char *path);
void					lib_next_line(char **buff);




t_map					*mk_map_cub(char *path);
void					mk_map_cub_assets(t_map *map);
void					mk_map_cub_assets_get_n_bmp(t_map *map, char **source, t_cub_assets *assets_checklist);
void					mk_map_cub_assets_get_s_bmp(t_map *map, char **source, t_cub_assets *assets_checklist);
void					mk_map_cub_assets_get_e_bmp(t_map *map, char **source, t_cub_assets *assets_checklist);
void					mk_map_cub_assets_get_w_bmp(t_map *map, char **source, t_cub_assets *assets_checklist);
void					mk_map_cub_assets_get_sprite(t_map *map, char **source, t_cub_assets *assets_checklist);
void					mk_map_cub_assets_get_res(t_map *map, char **source, t_cub_assets *assets_checklist);
void					mk_map_cub_assets_get_floor(t_map *map, char **source, t_cub_assets *assets_checklist);
void					mk_map_cub_assets_get_ceiling(t_map *map, char **source, t_cub_assets *assets_checklist);

void					mk_map_cub_get_walls(t_map *map);



#endif