#include "../../includes/cub3d.h"

void	_floor_casting(t_g *g)
{
	int				y;
	t_floor_extra	extra;
	float			row_distance;

	y = g->height / 2 + 1;
	while (y < g->height)
	{
		extra.ray_dir_x0 = g->dir_x - g->plane_x;
		extra.ray_dir_y0 = g->dir_y - g->plane_y;
		extra.ray_dir_x1 = g->dir_x + g->plane_x;
		extra.ray_dir_y1 = g->dir_y + g->plane_y;
		row_distance = (0.5 * g->height) / (y - g->height / 2);
		extra.floor_step_x = row_distance * (extra.ray_dir_x1 -
		extra.ray_dir_x0) / g->width;
		extra.floor_step_y = row_distance * (extra.ray_dir_y1 -
		extra.ray_dir_y0) / g->width;
		extra.floor_x = g->player_x + row_distance * extra.ray_dir_x0;
		extra.floor_y = g->player_y + row_distance * extra.ray_dir_y0;
		_floor_casting_extra(g, &extra, y);
		y++;
	}
}

void	_draw(t_g *g)
{
	int y;
	int x;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			g->img.data[y * g->width + x] = g->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	_window(t_g *g)
{
	g->win = mlx_new_window(g->mlx, g->width, g->height, "Cub3D - Cimyan");
	g->img.img = mlx_new_image(g->mlx, g->width, g->height);
	g->img.data = (int *)mlx_get_data_addr(g->img.img, &g->img.bpp,
	&g->img.size_l, &g->img.endian);
}
