#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libs/mlx/mlx.h"
# include "../libs/lib_c/lib.h"
# include "../libs/gnl/get_next_line.h"

# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

# define TEXSIZE 64

# define MOVE 0.05
# define ROT 0.05

# define K_A 0
# define K_S 1
# define K_D 2
# define K_W 13
# define K_LS 123
# define K_RS 124
# define K_ESC 53

# define FLOORTEX 4
# define CEILTEX 5

typedef struct	s_img
{
	void		*img;
	int			*data;

	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_sprite;

typedef struct	s_floor_extra
{
	float		ray_dir_x0;
	float		ray_dir_y0;
	float		ray_dir_x1;
	float		ray_dir_y1;
	float		floor_step_x;
	float		floor_step_y;
	float		floor_x;
	float		floor_y;
}				t_floor_extra;

typedef struct	s_sprite_extra
{
	double		sp_x;
	double		sp_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sp_screen_x;
	int			v_move_screen;
	int			sp_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sp_width;
	int			draw_start_x;
	int			draw_end_x;
	int			tex_x;
	int			tex_y;
}				t_sprite_extra;

typedef struct	s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		prp_wall_dist;
	double		step;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_id;
	double		wall_x;
	int			tex_x;
	double		tex_pos;
	int			tex_y;
}				t_ray;

typedef struct	s_g
{
	double		player_x;
	double		player_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_rs;
	int			key_ls;
	int			key_esc;
	t_img		img;
	int			**buf;
	double		*zbuf;
	int			**texture;
	t_sprite	*sprite;
	int			count_sprite;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*floor;
	char		*ceil;
	char		*sprite_s;
	char		*sprite_p;
	int			full_flags;
	char		**map;
	int			map_w;
	int			map_h;
	int			width;
	int			height;
	int			error;
	int			save;
}				t_g;

typedef	struct	s_gnl
{
	int			fd;
	int			read;
	int			empty_l;
}				t_gnl;

typedef struct	s_pair
{
	double		first;
	int			second;
}				t_pair;

void			_other_free(t_g *g);
void			_mlx_free(t_g *g);
void			_side_free(t_g *g);
void			_sprite_free(t_g *g);
void			_g_free(int id, t_g *g);

void			_split_free(char **new);
void			_texture_free(t_g *g);
void			_window_free(t_g *g);
void			_map_free(t_g *g);
void			_buf_free(t_g *g);

void			_load_image(t_g *g, int *texture, char *path, t_img *img);
void			_load_texture(t_g *g);
void			_init_texture(t_g *g);

void			_sprite_order(t_pair *orders, int amount);
void			_sprite_sort(t_g *g, int *order, double *dist, int amount);
void			_sprite_casting(t_g *g);
void			_sprite_stripe(int i, t_g *g,
t_sprite_extra *se, int *sprite_order);
void			_sprite_init(int i,
t_g *g, t_sprite_extra *se, int *sprite_order);

void			_floor_casting(t_g *g);
void			_draw(t_g *g);
void			_window(t_g *g);

void			_wall_casting(t_g *g);
void			_wall_texture(int x, int y, t_g *g, t_ray *ray);
void			_wall_calc(t_g *g, t_ray *ray);
void			_wall_dda(t_g *g, t_ray *ray);
void			_wall_distance(t_g *g, t_ray *ray);

void			_check_flags(t_g *g);
void			_error(t_g *g);
int				_exit(t_g *g);
void			_check_part(t_g *g, char *line, t_gnl *gnl);
void			_check_map(t_g *g);
void			_check_line(int x, int y, t_g *g, int height);

void			_key_straight(t_g *g);
void			_key_side(t_g *g);
void			_key_rotate(t_g *g);
int				_key_press(int key, t_g *g);
int				_key_release(int key, t_g *g);

void			_spawn(t_g *g, char position, int x, int y);

void			_parse_flags(t_g *g, char *line);
void			_check_map(t_g *g);
void			_size_map(t_g *g, char *file);

void			_map(t_g *g, char *file);
void			_spawn(t_g *g, char position, int x, int y);
char			*_set_map(t_g *g, char *line, int y);
void			_create_map(t_g *g, char *file);
void			_init(t_g *g, char *file);

void			_bmp_type(t_g *g, int fd);
void			_bmp_g(t_g *g, int fd);
void			_save_data(t_g *g, int fd);
int				_save(t_g *g);

void			_floor_casting_extra(t_g *g, t_floor_extra *extra, int y);
char			*_set_texture_extra(t_g *g, char *texture);

int				_check_ex(char *line, char *extension);
void			_check_folder(t_g *g);

void			_init_game(t_g *g);
int				_start_game(t_g *g);
void			_hooks(t_g g);
void			_init_keys(t_g *g);

#endif
