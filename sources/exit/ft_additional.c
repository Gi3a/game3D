
#include "../../includes/cub3d.h"

void	_split_free(char **new)
{
	int i;

	i = 0;
	while (new[i])
		free(new[i++]);
	free(new[i]);
	free(new);
}

void	_texture_free(t_g *g)
{
	int i;
	int count_texture;

	i = 0;
	count_texture = g->full_flags;
	while (i < count_texture)
	{
		if (g->texture[i])
			free(g->texture[i]);
		i++;
	}
	if (g->texture)
		free(g->texture);
}

void	_map_free(t_g *g)
{
	int x;

	x = 0;
	while (x < g->map_h)
	{
		if (g->map[x])
			free(g->map[x]);
		x++;
	}
	if (g->map)
		free(g->map);
}

void	_buf_free(t_g *g)
{
	int part;

	part = 0;
	while (part < g->height)
	{
		if (g->buf[part])
			free(g->buf[part]);
		part++;
	}
	if (g->buf)
		free(g->buf);
}
