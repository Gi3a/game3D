
#include "../../includes/cub3d.h"

void	_bmp_type(t_g *g, int fd)
{
	int					tmp;
	int					i;
	unsigned char		buf[14];

	i = 0;
	while (i < 14)
		buf[i++] = 0;
	buf[0] = (unsigned char)('B');
	buf[1] = (unsigned char)('M');
	tmp = 4 * (g->width * g->height) + 14 + 40;
	buf[2] = (unsigned char)(tmp % 256);
	buf[3] = (unsigned char)(tmp / 256 % 256);
	buf[4] = (unsigned char)(tmp / 256 / 256 % 256);
	buf[5] = (unsigned char)(tmp / 256 / 256 / 256);
	buf[10] = (unsigned char)(54);
	write(fd, buf, 14);
}

void	_bmp_g(t_g *g, int fd)
{
	int					i;
	unsigned char		buf[40];

	i = 0;
	while (i < 40)
		buf[i++] = 0;
	buf[0] = (unsigned char)(40);
	buf[4] = (unsigned char)(g->width % 256);
	buf[5] = (unsigned char)(g->width / 256 % 256);
	buf[6] = (unsigned char)(g->width / 256 / 256 % 256);
	buf[7] = (unsigned char)(g->width / 256 / 256 / 256);
	buf[8] = (unsigned char)(g->height % 256);
	buf[9] = (unsigned char)(g->height / 256 % 256);
	buf[10] = (unsigned char)(g->height / 256 / 256 % 256);
	buf[11] = (unsigned char)(g->height / 256 / 256 / 256);
	buf[12] = (unsigned char)(1);
	buf[14] = (unsigned char)(32);
	write(fd, buf, 40);
}

void	_save_data(t_g *g, int fd)
{
	int					tmp;
	int					i;
	int					j;
	unsigned char		buf[4];

	j = g->height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < g->width)
		{
			tmp = g->img.data[i + j * g->width];
			buf[0] = (unsigned char)(tmp % 256);
			buf[1] = (unsigned char)(tmp / 256 % 256);
			buf[2] = (unsigned char)(tmp / 256 / 256);
			buf[3] = (unsigned char)(0);
			write(fd, buf, 4);
			i++;
		}
		j--;
	}
}

int		_save(t_g *g)
{
	int				i;
	int				fd;

	i = 0;
	if (!(fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666)))
		g->error = 15;
	_error(g);
	_bmp_type(g, fd);
	_bmp_g(g, fd);
	_save_data(g, fd);
	close(fd);
	return (0);
}
