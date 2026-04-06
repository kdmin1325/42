/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:33:24 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/06 06:46:54 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fratol.h"

int	ft_check_run(int i, char **arr, t_win *c_num)
{
	c_num->depth = 150;
	c_num->zoom_x = 0;
	c_num->zoom_y = 0;
	c_num->size = 0;
	if (i == 2 && ft_strncmp(arr[1], "mandelbrot", 11) == 0)
	{
		c_num->c_imagin = 0;
		c_num->c_real = 0;
		return (1);
	}
	else if (i == 4 && ft_strncmp(arr[1], "julia", 6) == 0
		&& ft_strdouble(arr[2]) && ft_strdouble(arr[3]))
	{
		c_num->c_real = ft_atod(arr[2]);
		c_num->c_imagin = ft_atod(arr[3]);
		return (2);
	}
	ft_printf("./fractol (julia or mandelbrot) C(R) C(i)");
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	mlx;

	ft_check_run(argc, argv, &mlx);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, win_x, win_y, argv[1]);
	mlx.img = mlx_new_image(mlx.mlx, win_x, win_y);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpix, &mlx.line, &mlx.edi);
	ft_make_fratol(&mlx, 0, 0, 0);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mouse_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_hook, &mlx);
	mlx_loop(mlx.mlx);
}

//-I./minilibx-linux -L ./minilibx-linux -lmlx -lXext -lX11 -lm; ./a.out
//-I./minilibx -L ./minilibx -lmlx -framework OpenGL -framework AppKit; ./a.out