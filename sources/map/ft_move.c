#include "../../includes/cub3d.h"

void	_key_straight(t_g *g)
{
	if (g->key_w)
	{
		if (g->map[(int)(g->player_x +
			g->dir_x * MOVE)][(int)(g->player_y)] == '0')
			g->player_x += g->dir_x * MOVE;
		if (g->map[(int)(g->player_x)][(int)(g->player_y
			+ g->dir_y * MOVE)] == '0')
			g->player_y += g->dir_y * MOVE;
	}
	if (g->key_s)
	{
		if (g->map[(int)(g->player_x - g->dir_x
			* MOVE)][(int)(g->player_y)] == '0')
			g->player_x -= g->dir_x * MOVE;
		if (g->map[(int)(g->player_x)][(int)(g->player_y
			- g->dir_y * MOVE)] == '0')
			g->player_y -= g->dir_y * MOVE;
	}
}

void	_key_side(t_g *g)
{
	if (g->key_d)
	{
		if (g->map[(int)(g->player_x +
			g->plane_x * MOVE)][(int)(g->player_y)] == '0')
			g->player_x += g->plane_x * MOVE;
		if (g->map[(int)(g->player_x)][(int)(g->player_y
			+ g->plane_y * MOVE)] == '0')
			g->player_y += g->plane_y * MOVE;
	}
	if (g->key_a)
	{
		if (g->map[(int)(g->player_x - g->plane_x *
			MOVE)][(int)(g->player_y)] == '0')
			g->player_x -= g->plane_x * MOVE;
		if (g->map[(int)(g->player_x)][(int)(g->player_y -
			g->plane_y * MOVE)] == '0')
			g->player_y -= g->plane_y * MOVE;
	}
}

void	_key_rotate(t_g *g)
{
	double	old_dir_x;
	double	old_plane_x;

	if (g->key_rs)
	{
		old_dir_x = g->dir_x;
		g->dir_x = g->dir_x * cos(-ROT) - g->dir_y * sin(-ROT);
		g->dir_y = old_dir_x * sin(-ROT) + g->dir_y * cos(-ROT);
		old_plane_x = g->plane_x;
		g->plane_x = g->plane_x * cos(-ROT) - g->plane_y * sin(-ROT);
		g->plane_y = old_plane_x * sin(-ROT) + g->plane_y * cos(-ROT);
	}
	if (g->key_ls)
	{
		old_dir_x = g->dir_x;
		g->dir_x = g->dir_x * cos(ROT) - g->dir_y * sin(ROT);
		g->dir_y = old_dir_x * sin(ROT) + g->dir_y * cos(ROT);
		old_plane_x = g->plane_x;
		g->plane_x = g->plane_x * cos(ROT) - g->plane_y * sin(ROT);
		g->plane_y = old_plane_x * sin(ROT) + g->plane_y * cos(ROT);
	}
}
