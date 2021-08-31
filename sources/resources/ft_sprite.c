#include "../../includes/cub3d.h"

void		_sprite_order(t_pair *orders, int amount)
{
	int		i;
	int		j;
	t_pair	tmp;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void		_sprite_sort(t_g *g, int *order, double *dist, int amount)
{
	int		i;
	t_pair	*sprites;

	i = 0;
	if (!(sprites = (t_pair*)malloc(sizeof(t_pair) * amount)))
		g->error = 8;
	_error(g);
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	_sprite_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}

void		_sprite_stripe(int i, t_g *g, \
t_sprite_extra *se, int *sprite_order)
{
	int		stripe;
	int		y;
	int		color;

	stripe = se->draw_start_x;
	while (stripe < se->draw_end_x)
	{
		se->tex_x = (int)((256 * (stripe - (-se->sp_width / 2 +
			se->sp_screen_x)) * TEXSIZE / se->sp_width) / 256);
		if (se->transform_y > 0 && stripe > 0 && stripe < g->width &&
			se->transform_y < g->zbuf[stripe])
		{
			y = se->draw_start_y;
			while (y < se->draw_end_y)
			{
				se->tex_y = ((((y - se->v_move_screen) * 256 - g->height * 128 +
				se->sp_height * 128) * TEXSIZE) / se->sp_height) / 256;
				color = g->texture[g->sprite[sprite_order[i]].texture]
				[TEXSIZE * se->tex_y + se->tex_x];
				((color & 0x00FFFFFF) != 0) ? g->buf[y][stripe] = color : 0;
				y++;
			}
		}
		stripe++;
	}
}

void		_sprite_init(int i, t_g *g, t_sprite_extra *se, int *sprite_order)
{
	se->sp_x = g->sprite[sprite_order[i]].x - g->player_x;
	se->sp_y = g->sprite[sprite_order[i]].y - g->player_y;
	se->inv_det = 1.0 / (g->plane_x * g->dir_y - g->dir_x * g->plane_y);
	se->transform_x = se->inv_det * (g->dir_y * se->sp_x
	- g->dir_x * se->sp_y);
	se->transform_y = se->inv_det * (-g->plane_y *
		se->sp_x + g->plane_x * se->sp_y);
	se->sp_screen_x = (int)((g->width / 2) * (1 +
	se->transform_x / se->transform_y));
	se->v_move_screen = (int)(VMOVE / se->transform_y);
	se->sp_height = (int)fabs((g->height / se->transform_y) / VDIV);
	se->draw_start_y = -se->sp_height / 2 + g->height / 2 + se->v_move_screen;
	if (se->draw_start_y < 0)
		se->draw_start_y = 0;
	se->draw_end_y = se->sp_height / 2 + g->height / 2 + se->v_move_screen;
	if (se->draw_end_y >= g->height)
		se->draw_end_y = g->height - 1;
	se->sp_width = (int)fabs((g->height / se->transform_y) / UDIV);
	se->draw_start_x = -se->sp_width / 2 + se->sp_screen_x;
	if (se->draw_start_x < 0)
		se->draw_start_x = 0;
	se->draw_end_x = se->sp_width / 2 + se->sp_screen_x;
	if (se->draw_end_x >= g->width)
		se->draw_end_x = g->width - 1;
}

void		_sprite_casting(t_g *g)
{
	t_sprite_extra	se;
	int				i;
	int				sprite_order[g->count_sprite];
	double			sprite_distance[g->count_sprite];

	i = 0;
	while (i < g->count_sprite)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((g->player_x - g->sprite[i].x)
		* (g->player_x - g->sprite[i].x) +
		(g->player_y - g->sprite[i].y) * (g->player_y - g->sprite[i].y));
		i++;
	}
	_sprite_sort(g, sprite_order, sprite_distance, g->count_sprite);
	i = 0;
	while (i < g->count_sprite)
	{
		_sprite_init(i, g, &se, sprite_order);
		_sprite_stripe(i, g, &se, sprite_order);
		i++;
	}
}
