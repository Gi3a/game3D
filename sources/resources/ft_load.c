
#include "../../includes/cub3d.h"

void	_load_sprites(t_g *g)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while (i < g->map_h)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (g->map[i][j] == '2' || g->map[i][j] == '3')
			{
				g->sprite[k].x = i + 0.5;
				g->sprite[k].y = j + 0.5;
				(g->map[i][j] == '2') ? g->sprite[k].texture = 6 : 0;
				(g->map[i][j] == '3') ? g->sprite[k].texture = 7 : 0;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	_load_image(t_g *g, int *texture, char *path, t_img *img)
{
	int y;
	int x;

	y = 0;
	img->img = mlx_xpm_file_to_image(g->mlx, path,
		&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
		&img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(g->mlx, img->img);
}

void	_load_texture(t_g *g)
{
	t_img	img;

	if (!(g->sprite = (t_sprite*)malloc(sizeof(t_sprite) * g->count_sprite)))
		g->error = 8;
	_error(g);
	_load_sprites(g);
	_load_image(g, g->texture[0], g->north, &img);
	_load_image(g, g->texture[1], g->south, &img);
	_load_image(g, g->texture[2], g->west, &img);
	_load_image(g, g->texture[3], g->east, &img);
	_load_image(g, g->texture[4], g->floor, &img);
	_load_image(g, g->texture[5], g->ceil, &img);
	_load_image(g, g->texture[6], g->sprite_s, &img);
	_load_image(g, g->texture[7], g->sprite_p, &img);
}
