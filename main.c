#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define win_x 1000
#define win_y 1000
#define half_x 500
#define half_y 500

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
	int		line_len;
	int		endian;
}		t_data;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}		t_win;

void	ft_make_fratol(t_win *mlx, int state, int x, int y);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int is_pass(double sw_real_num, double sw_imagin_num)
{
	if(sw_real_num < 0)
		sw_real_num = -1 * sw_real_num;
	if(sw_imagin_num < 0)
		sw_imagin_num = -1 * sw_imagin_num;
	if(sw_real_num < 0.249 && sw_imagin_num < 0.498)
		return (1);
	return (0);
}

int	is_convergence(double real_num, double imagin_num, int n)
{
	double	z;
	int	i;
	double sw_imagin_num;
	double sw_real_num;
	double temp;

	int is_f = 0;

	if(is_pass(real_num, imagin_num))
		return (0);
	i = 0;
	sw_imagin_num = imagin_num;
	sw_real_num = real_num;
	while (i < n)
	{
		if((real_num * real_num + imagin_num * imagin_num) > 4)
		{
			return (i * i * i * 150);
		}
		//printf("log");
		temp = real_num;
		real_num = real_num * real_num - (imagin_num * imagin_num) + sw_real_num;
		imagin_num = (temp * imagin_num) * 2 + sw_imagin_num;
		i++;
	}
	return (0);
}

int key_hook(int key_code, void *param)
{
    t_win *mlx = (t_win *)param;
    printf("Key pressed: %d\n", key_code);
    return 0;
}

int mouse_hook(int button, int x, int y, void *param)
{
	static int size;

	printf("size: %d\n", size);
	t_win *mlx = (t_win *)param;
	if(button == 5)
	{
		size += 10;
		ft_make_fratol(mlx, size, x, y);
	}
	else if(button ==4)
	{
		size -= 10;
		ft_make_fratol(mlx, size, x, y);
	}
	return (0);
}

void	ft_make_fratol(t_win *mlx, int state, int x, int y)
{
	t_data	win;

	int i = 0;
	int j = 0;

	//int mlx_destroy_image(mlx.mlx, void *img_ptr);
	win.img = mlx_new_image(mlx->mlx, win_x, win_y);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_len, &win.endian);
	while (i <= win_x)
	{
		while (j <= win_y)
		{
			my_mlx_pixel_put(&win, i , j, is_convergence((double)(i - 500 + (x - 500)) / (300 + state), (double)(j - 500 + (y - 500)) / (300 + state), 50));
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, win.img, 0, 0);
}

int main(int argc, char **argv)
{
	printf("%d\n", argc);
	printf("%s\n", argv[0]);
	double time_spent;
	clock_t start = clock();
	t_win	mlx;
	t_data	win;

    mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, win_x, win_y, "test");
	win.img = mlx_new_image(mlx.mlx, win_x, win_y);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_len, &win.endian);

	int i = 0;
	int j = 0;
	while (i <= win_x)
	{
		while (j <= win_y)
		{
			my_mlx_pixel_put(&win, i , j, is_convergence((double)(i - half_x)/ 300, (double)(j - half_y) / 300, 5000));
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, win.img, 0, 0);
	
	clock_t end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", time_spent);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
}

//gcc main.c -I./minilibx-linux -L ./minilibx-linux -lmlx -lXext -lX11 -lm; ./a.out
