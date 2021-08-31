
#include "../../includes/cub3d.h"

void	_wall_distance(t_g *g, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (g->player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - g->player_x)
		* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (g->player_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - g->player_y)
		* ray->delta_dist_y;
	}
}

void	_wall_dda(t_g *g, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->ray_dir_x < 0)
				ray->side = 0;
			else
				ray->side = 2;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->ray_dir_y < 0)
				ray->side = 1;
			else
				ray->side = 3;
		}
		if (g->map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	_wall_calc(t_g *g, t_ray *ray)
{
	if (ray->side == 0 || ray->side == 2)
		ray->prp_wall_dist = (ray->map_x - g->player_x +
	(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->prp_wall_dist = (ray->map_y - g->player_y +
		(1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(g->height / ray->prp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + g->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + g->height / 2;
	if (ray->draw_end >= g->height)
		ray->draw_end = g->height - 1;
	ray->tex_id = (g->map[ray->map_x][ray->map_y] - '0') - 1;
	if (ray->side == 0 || ray->side == 2)
		ray->wall_x = g->player_y + ray->prp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = g->player_x + ray->prp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor((ray->wall_x));
}

void	_wall_texture(int x, int y, t_g *g, t_ray *ray)
{
	ray->tex_x = (int)(ray->wall_x * (double)TEXSIZE);
	if ((ray->side == 0 || ray->side == 2) && ray->ray_dir_x > 0)
		ray->tex_x = TEXSIZE - ray->tex_x - 1;
	if ((ray->side == 1 || ray->side == 3) && ray->ray_dir_y < 0)
		ray->tex_x = TEXSIZE - ray->tex_x - 1;
	if ((ray->side == 0 || ray->side == 2) && ray->ray_dir_x >= 0)
		ray->tex_id = 1;
	else if ((ray->side == 0 || ray->side == 2) && ray->ray_dir_x < 0)
		ray->tex_id = 0;
	else if ((ray->side == 1 || ray->side == 3) && ray->ray_dir_y < 0)
		ray->tex_id = 2;
	else
		ray->tex_id = 3;
	ray->step = 1.0 * TEXSIZE / ray->line_height;
	ray->tex_pos = (ray->draw_start - g->height / 2 +
	ray->line_height / 2) * ray->step;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TEXSIZE - 1);
		ray->tex_pos += ray->step;
		g->buf[y][x] = g->texture[ray->tex_id]
		[TEXSIZE * ray->tex_y + ray->tex_x];
		y++;
	}
}

void	_wall_casting(t_g *g)
{
	int			x;
	int			y;
	float		camera_x;
	t_ray		ray;

	x = 0;
	while (x < g->width)
	{
		camera_x = 2 * x / (double)g->width - 1;
		ray.ray_dir_x = g->dir_x + g->plane_x * camera_x;
		ray.ray_dir_y = g->dir_y + g->plane_y * camera_x;
		ray.map_x = (int)g->player_x;
		ray.map_y = (int)g->player_y;
		ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
		ray.delta_dist_y = fabs(1 / ray.ray_dir_y);
		ray.hit = 0;
		_wall_distance(g, &ray);
		_wall_dda(g, &ray);
		_wall_calc(g, &ray);
		y = ray.draw_start;
		_wall_texture(x, y, g, &ray);
		g->zbuf[x] = ray.prp_wall_dist;
		x++;
	}
}
