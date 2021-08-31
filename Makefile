NAME =	cub3D
FLAGS =	-Werror -Wextra -Wall -g
HEAD =	includes/cub3d.h

SRCS =	sources/cub3d.c \
		sources/map/ft_map.c \
		sources/map/ft_key.c \
		sources/map/ft_move.c \
		sources/exit/ft_exit.c \
		sources/exit/ft_free.c \
		sources/errors/ft_check.c \
		sources/errors/ft_error.c \
		sources/map/ft_parse_map.c \
		sources/functions/ft_wall.c \
		sources/exit/ft_additional.c \
		sources/functions/ft_save.c \
		sources/resources/ft_load.c \
		sources/resources/ft_extra.c \
		sources/resources/ft_sprite.c \
		sources/functions/ft_raycasting.c \

OBJS =	$(SRCS:.c=.o)

LIBFT =	libs/libft/libft.a
LIBLMX = libs/mlx/libmlx.a
LIBGNL = libs/gnl/*.c -D BUFFER_SIZE=30

MLX =	-framework OpenGL -framework AppKit

RM = rm -f

$(NAME): $(OBJS) $(HEAD) $(LIBFT) $(LIBLMX)
	gcc $(OBJS) $(MLX) $(LIBFT) $(LIBLMX) -o $(NAME) $(LIBGNL)

$(LIBFT): $(LIBLMX)
	@$(MAKE) -C libs/libft
	@make bonus -C libs/libft

$(LIBLMX):
	@$(MAKE) -C libs/mlx

$(OBJS): %.o:%.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		@make clean -C libs/libft
		@make clean -C libs/mlx
		$(RM) *.bmp

fclean:	clean
		$(RM) $(NAME)
		@make fclean -C libs/libft

re:		fclean all

.PHONY:		all clean fclean re
