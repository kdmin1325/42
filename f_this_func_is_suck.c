/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_this_func_is_suck.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 03:05:46 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/07 21:00:43 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fratol.h"

void	ft_make_fratol(t_win *mlx, size_t zoom, double x, double y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx->old_img = mlx->img;
	mlx->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpix, &mlx->line, &mlx->edi);
	while (i < WIN_X)
	{
		while (j < WIN_Y)
		{
			ft_pixel_put(mlx, i, j, pixel_render(i + x, j + y, zoom, mlx));
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->old_img);
}

int	pixel_render(double r, double i, size_t zoom, t_win *num)
{
	int		t;
	double	local_r;
	double	local_i;
	double	temp;

	t = 0;
	r = (r - HALF_X) / (zoom + BASE);
	local_r = r * (num->c_real == 0 && num->c_imagin == 0);
	i = (i - HALF_Y) / (zoom + BASE);
	local_i = i * (num->c_real == 0 && num->c_imagin == 0);
	if (is_pass(r, i) && num->c_real == 0 && num->c_imagin == 0)
		return (ft_color_set(0, 0) + 100);
	while (t < num->depth)
	{
		if ((r * r + i * i) > 4)
		{
			return (ft_color_set(t, 0) + 100);
		}
		temp = r;
		r = r * r - i * i + local_r + num->c_real;
		i = 2 * temp * i + local_i + num->c_imagin;
		t++;
	}
	return (ft_color_set(0, 0) + 100);
}
