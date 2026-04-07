/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fratol.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:22:19 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/07 20:58:14 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRATOL_H
# define FRATOL_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <time.h>
# include "libft/libft.h"

# define WIN_X 1000
# define WIN_Y 1000
# define HALF_X 500
# define HALF_Y 500
# define BASE 300

typedef struct s_win
{
	void	*img;
	void	*old_img;
	char	*addr;
	int		bpix;
	int		line;
	int		edi;
	void	*mlx;
	void	*mlx_win;
	double	c_real;
	double	c_imagin;
	int		depth;
	double	zoom_x;
	double	zoom_y;
	size_t	size;
}		t_win;

void	ft_pixel_put(t_win *data, int x, int y, int color);
int		is_pass(double real_num, double imagin_num);
int		pixel_render(double r, double i, size_t zoom, t_win *num);
int		key_hook(int key_code, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		close_hook(void *param);
int		ft_color_set(int c, unsigned int flag);
int		ft_change_color(int c);

int		ft_check_run(int i, char **arr, t_win *c_num);
void	ft_make_fratol(t_win *mlx, size_t state, double x, double y);
int		ft_outpoint(t_win *mlx);
#endif
