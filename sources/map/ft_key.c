

#include "../../includes/cub3d.h"

int		_key_press(int key, t_g *g)
{
	if (key == K_ESC)
		_exit(g);
	else if (key == K_W)
		g->key_w = 1;
	else if (key == K_A)
		g->key_a = 1;
	else if (key == K_S)
		g->key_s = 1;
	else if (key == K_D)
		g->key_d = 1;
	else if (key == K_RS)
		g->key_rs = 1;
	else if (key == K_LS)
		g->key_ls = 1;
	return (0);
}

int		_key_release(int key, t_g *g)
{
	if (key == K_ESC)
		_exit(g);
	else if (key == K_W)
		g->key_w = 0;
	else if (key == K_A)
		g->key_a = 0;
	else if (key == K_S)
		g->key_s = 0;
	else if (key == K_D)
		g->key_d = 0;
	else if (key == K_RS)
		g->key_rs = 0;
	else if (key == K_LS)
		g->key_ls = 0;
	return (0);
}
