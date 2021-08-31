#include "../../includes/cub3d.h"

void	_set_resolution(t_g *g, char *line)
{
	char **new;

	if (!(new = _split(line, ' ')))
		g->error = 8;
	(!(new[1] && new[2])) ? g->error = 7 : 0;
	_error(g);
	g->width = _atoi(new[1]);
	g->height = _atoi(new[2]);
	if (g->width > 2560)
		g->width = 2560;
	else if (g->width < 400)
		g->width = 400;
	if (g->height > 1440)
		g->height = 1440;
	else if (g->height < 200)
		g->height = 200;
	_split_free(new);
}

void	_size_map(t_g *g, char *file)
{
	int		fd;
	char	*line;
	int		read;

	line = 0;
	fd = open(file, O_RDONLY);
	while ((read = get_next_line(fd, &line)) != 0)
	{
		if (!(_strchr("NEWSRFCSP", line[0])))
		{
			if ((int)_strlen(line) > g->map_w)
				g->map_w = (int)_strlen(line);
			g->map_h++;
		}
		free(line);
	}
	g->map_h++;
	free(line);
	(read == -1) ? g->error = 4 : 0;
}

void	_set_texture(t_g *g, char *line)
{
	char flag;
	char **new;

	flag = line[0];
	if (!(new = _split(line + 2, ' ')))
		g->error = 8;
	g->full_flags = g->full_flags + 1;
	if (flag == 'N')
		g->north = _set_texture_extra(g, new[0]);
	else if (flag == 'S' && line[1] == 'O')
		g->south = _set_texture_extra(g, new[0]);
	else if (flag == 'E')
		g->east = _set_texture_extra(g, new[0]);
	else if (flag == 'W')
		g->west = _set_texture_extra(g, new[0]);
	else if (flag == 'F')
		g->floor = _set_texture_extra(g, new[0]);
	else if (flag == 'C')
		g->ceil = _set_texture_extra(g, new[0]);
	else if (flag == 'S' && line[1] == ' ')
		g->sprite_s = _set_texture_extra(g, new[0]);
	else
		g->sprite_p = _set_texture_extra(g, new[0]);
	_split_free(new);
}

void	_parse_flags(t_g *g, char *line)
{
	char flag;

	flag = *line;
	if (flag == 'R' && !g->width)
		_set_resolution(g, line);
	else if ((flag == 'F' || flag == 'C') && line[1] == ' ')
		_set_texture(g, line);
	else if ((flag == 'N' || flag == 'S' || flag == 'W' || flag == 'E')
	&& (line[1] == 'O' || line[1] == 'E' || line[1] == 'A'))
		_set_texture(g, line);
	else if ((flag == 'S' || flag == 'P') && line[1] == ' ')
		_set_texture(g, line);
	else if (flag != 0)
		g->error = 3;
	_error(g);
}
