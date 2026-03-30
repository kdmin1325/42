#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

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

typedef struct s_thread
{
	t_data	*img;
	int		start_y;
	int		end_y;
	int		state;
	int		offset_x;
	int		offset_y;
}	t_thread;

/* ================= 스레드 개수 ================= */
int get_thread_count(void)
{
	int n = sysconf(_SC_NPROCESSORS_ONLN);

	if (n < 1)
		return (4);
	if (n > 16) // 너무 많으면 오히려 느려짐 방지
		return (16);
	return (n);
}

/* ================= 픽셀 ================= */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* ================= 빠른 탈출 ================= */
int is_pass(double r, double i)
{
	if (r < 0) r *= -1;
	if (i < 0) i *= -1;
	return (r < 0.249 && i < 0.498);
}

/* ================= 프랙탈 ================= */
int	is_convergence(double real, double imag, int max_iter)
{
	double	temp;
	double	cr = real;
	double	ci = imag;
	int		i = 0;

	if (is_pass(real, imag))
		return (0);

	while (i < max_iter)
	{
		if ((real * real + imag * imag) > 4.0)
			return (i * i * i * 150);

		temp = real;
		real = real * real - imag * imag + cr;
		imag = 2 * temp * imag + ci;
		i++;
	}
	return (0);
}

/* ================= 스레드 렌더 ================= */
void	*render_thread(void *arg)
{
	t_thread *t = (t_thread *)arg;
	int x;
	int y;

	x = 0;
	while (x < win_x)
	{
		y = t->start_y;
		while (y < t->end_y)
		{
			my_mlx_pixel_put(t->img, x, y,
				is_convergence(
					(double)(x - half_x + t->offset_x) / (300 + t->state),
					(double)(y - half_y + t->offset_y) / (300 + t->state),
					5000));
			y++;
		}
		x++;
	}
	return NULL;
}

/* ================= 렌더 함수 ================= */
void	ft_make_fratol(t_win *mlx, int state, int mx, int my)
{
	t_data		win;
	int			thread_count = get_thread_count();
	pthread_t	threads[thread_count];
	t_thread	tdata[thread_count];
	int			i;
	int			slice;

	win.img = mlx_new_image(mlx->mlx, win_x, win_y);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel,
			&win.line_len, &win.endian);

	slice = win_y / thread_count;

	i = 0;
	while (i < thread_count)
	{
		tdata[i].img = &win;
		tdata[i].start_y = i * slice;
		tdata[i].end_y = (i == thread_count - 1) ? win_y : (i + 1) * slice;
		tdata[i].state = state;
		tdata[i].offset_x = mx - half_x;
		tdata[i].offset_y = my - half_y;

		pthread_create(&threads[i], NULL, render_thread, &tdata[i]);
		i++;
	}

	i = 0;
	while (i < thread_count)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, win.img, 0, 0);
}

/* ================= 입력 ================= */
int key_hook(int key_code, void *param)
{
	(void)param;
	printf("Key: %d\n", key_code);
	return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
	static int zoom = 0;
	t_win *mlx = (t_win *)param;

	if (button == 5)
		zoom += 10;
	else if (button == 4)
		zoom -= 10;

	printf("zoom: %d | threads: %d\n", zoom, get_thread_count());
	ft_make_fratol(mlx, zoom, x, y);
	return (0);
}

/* ================= 초기 렌더 ================= */
void	initial_render(t_win *mlx, t_data *win)
{
	int			thread_count = get_thread_count();
	pthread_t	threads[thread_count];
	t_thread	tdata[thread_count];
	int			i;
	int			slice;

	slice = win_y / thread_count;

	i = 0;
	while (i < thread_count)
	{
		tdata[i].img = win;
		tdata[i].start_y = i * slice;
		tdata[i].end_y = (i == thread_count - 1) ? win_y : (i + 1) * slice;
		tdata[i].state = 0;
		tdata[i].offset_x = 0;
		tdata[i].offset_y = 0;

		pthread_create(&threads[i], NULL, render_thread, &tdata[i]);
		i++;
	}

	i = 0;
	while (i < thread_count)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

/* ================= main ================= */
int main(void)
{
	t_win	mlx;
	t_data	win;

	clock_t start = clock();

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, win_x, win_y, "fractol");

	win.img = mlx_new_image(mlx.mlx, win_x, win_y);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel,
			&win.line_len, &win.endian);

	initial_render(&mlx, &win);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, win.img, 0, 0);

	printf("Time: %f sec\n",
		(double)(clock() - start) / CLOCKS_PER_SEC);

	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
}

//gcc moiult.c -I./minilibx -L./minilibx -lmlx -framework OpenGL -framework AppKit -lpthread -O2; ./a.out