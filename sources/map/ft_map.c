

#include "../../includes/cub3d.h"

void	_spawn(t_g *g, char position, int x, int y)
{
	(g->player_x != 0) ? g->error = 11 : 0;
	g->player_x = (float)y + 0.5;
	g->player_y = (float)x + 0.5;
	if (position == 'N' || position == 'S')
	{
		g->dir_x = (position == 'N') ? -1 : 1;
		g->dir_y = 0;
		g->plane_x = 0;
		g->plane_y = (position == 'N') ? 0.66 : -0.66;
	}
	else if (position == 'W' || position == 'E')
	{
		g->dir_x = 0;
		g->dir_y = (position == 'W') ? -1 : 1;
		g->plane_x = (position == 'W') ? -0.66 : 0.66;
		g->plane_y = 0;
	}
	_error(g);
}

char	*_set_map(t_g *g, char *line, int y)
{
	int		i;
	int		size;
	char	*new;

	size = _strlen(line);
	i = 0;
	if (!(new = (char*)malloc(size * sizeof(char*))))
		g->error = 8;
	_error(g);
	while (line[i])
	{
		if (_strchr("NEWS", line[i]))
		{
			_spawn(g, line[i], i, y);
			line[i] = '0';
		}
		else if (_strchr("23", line[i]))
			g->count_sprite++;
		new[i] = line[i];
		i++;
	}
	new[size] = '\0';
	return (new);
}

void	_check_part(t_g *g, char *line, t_gnl *gnl)
{
	if ((_strchr("NEWSRFCSP", line[0])))
	{
		if (g->full_flags == 8 && gnl->empty_l == 1)
			g->error = 18;
		else
			_parse_flags(g, line);
	}
	_error(g);
}

void	_create_map(t_g *g, char *file)
{
	t_gnl	gnl;
	char	*line;
	int		y;

	line = 0;
	y = 0;
	gnl.empty_l = 0;
	gnl.fd = open(file, O_RDONLY);
	while ((gnl.read = get_next_line(gnl.fd, &line)) > 0)
	{
		if (!(_strchr("NEWSRFCSP", line[0])))
		{
			gnl.empty_l = 1;
			g->map[y] = _set_map(g, line, y);
			y++;
		}
		else
			_check_part(g, line, &gnl);
		free(line);
	}
	g->map[y] = _set_map(g, line, y);
	free(line);
	(!g->player_x) ? g->error = 14 : 0;
	(gnl.read == -1) ? g->error = 4 : 0;
	_error(g);
}

void	_map(t_g *g, char *file)
{
	g->map_w = 0;
	g->map_h = 0;
	g->count_sprite = 0;
	_size_map(g, file);
	if (!(g->map = (char**)malloc((g->map_h) * sizeof(char*))))
		g->error = 8;
	_create_map(g, file);
	_check_flags(g);
	_error(g);
	_init_game(g);
	_error(g);
	_init_texture(g);
	_error(g);
	_check_map(g);
	_error(g);
	_load_texture(g);
	_error(g);
}
