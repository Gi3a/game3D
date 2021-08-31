
#include "../../includes/cub3d.h"

void	_g_free(int id, t_g *g)
{
	if (id == 2)
	{
		_mlx_free(g);
		exit(1);
	}
	else if (id == 1)
	{
		_sprite_free(g);
		_side_free(g);
		_other_free(g);
		_mlx_free(g);
	}
}

void	_sprite_free(t_g *g)
{
	(g->sprite) ? free(g->sprite) : 0;
	(g->sprite_s) ? free(g->sprite_s) : 0;
	(g->sprite_p) ? free(g->sprite_p) : 0;
}

void	_side_free(t_g *g)
{
	(g->north) ? free(g->north) : 0;
	(g->south) ? free(g->south) : 0;
	(g->west) ? free(g->west) : 0;
	(g->east) ? free(g->east) : 0;
	(g->floor) ? free(g->floor) : 0;
	(g->ceil) ? free(g->ceil) : 0;
}

void	_mlx_free(t_g *g)
{
	(g->img.img) ? free(g->img.img) : 0;
	(g->win) ? free(g->win) : 0;
	(g->mlx) ? free(g->mlx) : 0;
}

void	_other_free(t_g *g)
{
	(g->zbuf) ? free(g->zbuf) : 0;
	(g->texture) ? _texture_free(g) : 0;
	(g->map) ? _map_free(g) : 0;
	(g->buf) ? _buf_free(g) : 0;
}
