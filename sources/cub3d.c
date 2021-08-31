

#include "../includes/cub3d.h"

void	_init(t_g *g, char *file)
{
	g->error = 0;
	(!(_strnstr(file, ".cub", _strlen(file)))) ? g->error = 10 : 0;
	(open(file, O_RDONLY) == -1) ? g->error = 10 : 0;
	_error(g);
}

int		_start_game(t_g *g)
{
	_floor_casting(g);
	_wall_casting(g);
	_sprite_casting(g);
	_draw(g);
	_key_straight(g);
	_key_side(g);
	_key_rotate(g);
	return (0);
}

void	_init_keys(t_g *g)
{
	g->key_a = 0;
	g->key_w = 0;
	g->key_s = 0;
	g->key_d = 0;
	g->key_rs = 0;
	g->key_ls = 0;
	g->key_esc = 0;
	g->error = 0;
}

void	_init_game(t_g *g)
{
	int	i;
	int	j;

	i = 0;
	_init_keys(g);
	if (!(g->buf = (int**)malloc(sizeof(int*) * g->height)))
		g->error = 8;
	while (i < g->height)
	{
		if (!(g->buf[i] = (int*)malloc(g->width * sizeof(int))))
			g->error = 8;
		i++;
	}
	if (!(g->zbuf = (double*)malloc(sizeof(double) * g->width)))
		g->error = 8;
	i = -1;
	while (++i < g->height)
	{
		j = -1;
		while (++j < g->width)
			g->buf[i][j] = 0;
	}
	_error(g);
}

int		main(int argc, char **argv)
{
	t_g g;

	if (argc == 2 || argc == 3)
	{
		_init(&g, argv[1]);
		if (!(g.mlx = mlx_init()))
			g.error = 2;
		_error(&g);
		if (argc == 3)
		{
			if (!(_strncmp(argv[2], "--save", _strlen("--save"))))
				g.save = 1;
			else
				g.error = 17;
		}
		_error(&g);
		_map(&g, argv[1]);
		_hooks(g);
	}
	else if (argc == 1)
		g.error = 5;
	else
		g.error = 9;
	_error(&g);
	return (0);
}
