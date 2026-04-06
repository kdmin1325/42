# SRCS		=	main.c main_utils.c LIBFTMAKE
# OBJS		= $(SRCS:.c=.o)

# CC			= cc
# RM			= rm -f
# CFLAGS		= -Wall -Wextra -Werror
# MLXFLAGS	= -I./minilibx-linux -L ./minilibx-linux -lmlx -lXext -lX11 -lm
# LIBFTMAKE	= ./libft

# NAME		= fractol.a
# OBJECTS = $(OBJS)
# all:			sub-build $(NAME)

# sub-build:
# 	$(MAKE) -C $(LIBFTMAKE)

# $(NAME):		$(OBJECTS)
# 				ar rcs $(NAME) $(OBJECTS)
# 				$(CC) $(NAME) $(MLXFLAGS) sub-build $(MLXFLAGS)

# clean:
# 				$(RM) $(OBJS)

# fclean:			clean
# 				$(RM) $(NAME)

# re:				fclean $(NAME)

# fre:			fclean $(NAME)
# 				$(RM) $(OBJS)

# .PHONY:			all clean fclean re


SRCS		= main.c f_mlx_hook_is_hummm.c f_this_func_is_suck.c f_etc_func.c
OBJS		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I./minilibx-linux
MLXFLAGS	= -L./minilibx-linux -lmlx -lXext -lX11 -lm

LIBFTMAKE	= ./libft
LIBFT		= ./libft/libftprintf.a

NAME		= fractol

all: sub-build $(NAME)

sub-build:
	$(MAKE) -C $(LIBFTMAKE)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTMAKE) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTMAKE) fclean

re: fclean all

.PHONY: all clean fclean re sub-build