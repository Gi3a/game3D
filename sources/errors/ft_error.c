

#include "../../includes/cub3d.h"

void		_error(t_g *g)
{
	if (g->error)
	{
		(g->error == 1) ? perror(" Error\n Window is not set") : 0;
		(g->error == 2) ? perror(" Error\n MLX") : 0;
		(g->error == 3) ? perror(" Error\n Texture is not set") : 0;
		(g->error == 4) ? perror(" Error\n Reading file") : 0;
		(g->error == 5) ? perror(" Error\n Map is not choose") : 0;
		(g->error == 6) ? perror(" Error\n Missing config file") : 0;
		(g->error == 7) ? perror(" Error\n Resolution is not set") : 0;
		(g->error == 8) ? perror(" Error\n Memory is not set") : 0;
		(g->error == 9) ? perror(" Error\n Too many arguments") : 0;
		(g->error == 10) ? perror(" Error\n Map path is not set") : 0;
		(g->error == 11) ? perror(" Error\n Too many spawns users") : 0;
		(g->error == 12) ? perror(" Error\n Incorrect texture extn .xpm") : 0;
		(g->error == 13) ? perror(" Error\n Incorrect texture path") : 0;
		(g->error == 14) ? perror(" Error\n Spawn users is not set") : 0;
		(g->error == 15) ? perror(" Error\n Incorrect write file .bmp") : 0;
		(g->error == 16) ? perror(" Error\n Map is not valid") : 0;
		(g->error == 17) ? perror(" Error\n Undefined command, --save") : 0;
		(g->error == 18) ? perror(" Error\n Detected \\n in map") : 0;
		_g_free(2, g);
	}
}
