

#include "../../includes/cub3d.h"

int			_check_ex(char *line, char *extension)
{
	int size_ex;
	int size_line;

	size_line = _strlen(line) - 1;
	size_ex = _strlen(extension) - 1;
	while (extension[size_ex])
	{
		if (extension[size_ex] != line[size_line])
			return (0);
		size_ex--;
		size_line--;
	}
	return (1);
}

void		_check_line(int x, int y, t_g *g, int height)
{
	if (x > height - 1 || x < 0
	|| y > (int)(_strlen(g->map[x]) - 1) || y < 0
	|| g->map[x][y] == ' ')
		g->error = 16;
	_error(g);
	if (g->map[x][y] == '1' || g->map[x][y] == 'V' ||
		g->map[x][y] == '2' || g->map[x][y] == '3')
		return ;
	if (g->map[x][y] == '0')
		g->map[x][y] = 'V';
	_check_line(x + 1, y, g, height);
	_check_line(x + 1, y - 1, g, height);
	_check_line(x - 1, y, g, height);
	_check_line(x - 1, y - 1, g, height);
	_check_line(x, y + 1, g, height);
	_check_line(x, y - 1, g, height);
}

void		_check_flags(t_g *g)
{
	(!(g->height && g->width)) ? g->error = 7 : 0;
	(g->full_flags != 8) ? g->error = 3 : 0;
	_error(g);
	!(_check_ex(g->north, ".xpm")) ? g->error = 12 : 0;
	!(_check_ex(g->south, ".xpm")) ? g->error = 12 : 0;
	!(_check_ex(g->west, ".xpm")) ? g->error = 12 : 0;
	!(_check_ex(g->east, ".xpm")) ? g->error = 12 : 0;
	!(_check_ex(g->floor, ".xpm")) ? g->error = 12 : 0;
	!(_check_ex(g->ceil, ".xpm")) ? g->error = 12 : 0;
	!(_check_ex(g->sprite_s, ".xpm")) ? g->error = 12 : 0;
	!(_check_ex(g->sprite_p, ".xpm")) ? g->error = 12 : 0;
	_error(g);
	_check_folder(g);
}

void		_check_folder(t_g *g)
{
	(open(g->north, O_RDONLY) == -1) ? g->error = 13 : 0;
	(open(g->south, O_RDONLY) == -1) ? g->error = 13 : 0;
	(open(g->west, O_RDONLY) == -1) ? g->error = 13 : 0;
	(open(g->east, O_RDONLY) == -1) ? g->error = 13 : 0;
	(open(g->floor, O_RDONLY) == -1) ? g->error = 13 : 0;
	(open(g->ceil, O_RDONLY) == -1) ? g->error = 13 : 0;
	(open(g->sprite_s, O_RDONLY) == -1) ? g->error = 13 : 0;
	(open(g->sprite_p, O_RDONLY) == -1) ? g->error = 13 : 0;
	_error(g);
}

void		_check_map(t_g *g)
{
	int		i;
	int		j;

	_check_line(g->player_x - 0.5, g->player_y - 0.5, g, g->map_h);
	i = 0;
	while (i < g->map_h)
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'V')
				g->map[i][j] = '0';
			j++;
		}
		i++;
	}
}
