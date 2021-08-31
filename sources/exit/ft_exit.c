

#include "../../includes/cub3d.h"

int		_exit(t_g *g)
{
	_error(g);
	_g_free(1, g);
	exit(0);
	return (0);
}
