#include "cub3d.h"

t_texture				*lib_get_texture(char *path)
{
	t_texture *texture;
	char *buff;
	int *temp;
	int len;
	int offset;

	int i;
	int j;

	i  = 0;
	j = 0;

	if (!(texture = malloc(sizeof(t_texture))))
		lib_do_exit("lib_get_texture malloc fail\n");
	len = lib_get_file_len(path);
	buff = lib_open_file(path);
	offset = *((int *)(buff + 10));
	temp = (int *)(buff + offset);
	texture->size = (len - offset) / 4;
	texture->size_v = *((int *)(buff + 18));
	texture->size_h = *((int *)(buff + 22));
	if (!(texture->bitmap = malloc(sizeof(int *) * texture->size_v)))
		lib_do_exit("lib_get_texture bitmap x malloc fail\n");
	while (i < texture->size_v)
	{
		if (!(texture->bitmap[i] = malloc(sizeof(int) * texture->size_h)))
			lib_do_exit("lib_get_texture bitmap y malloc fail\n");
		i++;
	}
	i = 0;
	while (i < texture->size_v)
	{
		j = 0;
		while (j < texture->size_h)
		{
			texture->bitmap[i][j] = *temp++;
			j++;
		}
		i++;
	}
	free(buff);
	return (texture);
}