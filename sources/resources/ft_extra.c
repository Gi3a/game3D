#include "../../includes/cub3d.h"

void	_hooks(t_g g)
{
	_window(&g);
	(g.save == 1) ? _start_game(&g) : 0;
	(g.save == 1) ? _save(&g) : 0;
	(g.save == 1) ? _exit(&g) : 0;
	mlx_loop_hook(g.mlx, &_start_game, &g);
	mlx_hook(g.win, 2, 0, &_key_press, &g);
	mlx_hook(g.win, 3, 0, &_key_release, &g);
	mlx_hook(g.win, 17, 0, &_exit, &g);
	mlx_loop(g.mlx);
}

void	_floor_casting_extra(t_g *g, t_floor_extra *extra, int y)
{
	int x;
	int color;
	int tx;
	int ty;

	x = 0;
	while (x < g->width)
	{
		tx = (int)(TEXSIZE * (extra->floor_x -
		(int)(extra->floor_x))) & (TEXSIZE - 1);
		ty = (int)(TEXSIZE * (extra->floor_y -
		(int)(extra->floor_y))) & (TEXSIZE - 1);
		extra->floor_x += extra->floor_step_x;
		extra->floor_y += extra->floor_step_y;
		color = g->texture[FLOORTEX][TEXSIZE * ty + tx];
		g->buf[y][x] = color;
		color = g->texture[CEILTEX][TEXSIZE * ty + tx];
		g->buf[g->height - y - 1][x] = color;
		++x;
	}
}

void	_init_texture(t_g *g)
{
	int i;
	int j;

	i = 0;
	if (!(g->texture = (int **)malloc(sizeof(int *) * g->full_flags)))
		g->error = 8;
	while (i < g->full_flags)
	{
		if (!(g->texture[i] = (int *)malloc(sizeof(int) *
			(TEXSIZE * TEXSIZE))))
			g->error = 8;
		i++;
	}
	i = 0;
	while (i < g->full_flags)
	{
		j = 0;
		while (j < TEXSIZE * TEXSIZE)
		{
			g->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	_error(g);
}

char	*_set_texture_extra(t_g *g, char *texture)
{
	char *new;

	if (!(new = _strdup(texture)))
		g->error = 8;
	return (new);
}
