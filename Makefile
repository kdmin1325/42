SRCS		= main.c f_mlx_hook_is_hummm.c f_this_func_is_suck.c f_etc_func.c
OBJS		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I./minilibx-linux
MLXFLAGS	= -L./minilibx-linux -lmlx -lXext -lX11 -lm

LIBFTMAKE	= ./libft
LIBFT		= ./libft/libftprintf.a

MLXDIR		= ./minilibx-linux
MLX			= $(MLXDIR)/libmlx.a

NAME		= fractol

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTMAKE)

$(MLX):
	$(MAKE) -C $(MLXDIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTMAKE) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTMAKE) fclean

re: fclean all

.PHONY: all clean fclean re