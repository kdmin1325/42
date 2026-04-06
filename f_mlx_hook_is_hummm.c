/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mlx_hook_is_hummm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 03:08:39 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/06 06:02:30 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fratol.h"

int	close_hook(void *param)
{
	t_win	*mlx;

	mlx = (t_win *)param;
	ft_outpoint(mlx);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_win			*mlx;

	mlx = (t_win *)param;
	mlx->depth += ((button == 1) * 10 - (button == 3) * 10);
	mlx->zoom_x += (x - half_x) * 0.1 * ((button == 5) || (button == 4));
	mlx->zoom_y += (y - half_y) * 0.1 * ((button == 5) || (button == 4));
	mlx->size += 10 * (button == 5);
	mlx->size -= 10 * (button == 4) * (mlx->size + base > 0);
	ft_make_fratol(mlx, mlx->size, mlx->zoom_x, mlx->zoom_y);
	return (0);
}

int	key_hook(int key_code, void *param)
{
	t_win	*mlx;

	mlx = (t_win *)param;
	if (key_code == 65307)
		ft_outpoint(mlx);
	else if (key_code == 99)
		ft_color_set(100, 1);
	mlx->size += (key_code == 61) * 10 ;
	mlx->size -= (key_code == 45) * 10 * (mlx->size + base > 0);
	mlx->zoom_x -= half_x * 0.1 * (key_code == 65361);
	mlx->zoom_x += half_x * 0.1 * (key_code == 65363);
	mlx->zoom_y -= half_y * 0.1 * (key_code == 65362);
	mlx->zoom_y += half_y * 0.1 * (key_code == 65364);
	ft_make_fratol(mlx, mlx->size, mlx->zoom_x, mlx->zoom_y);
	return (0);
}

int	ft_outpoint(t_win *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (0);
}

void	ft_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bpix / 8));
	*(unsigned int *)dst = color;
}
