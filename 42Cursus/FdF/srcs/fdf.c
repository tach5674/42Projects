/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:40:59 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/24 19:40:08 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (data->endian == 0)
	{
		dst[0] = (color >> 16) & 0xFF;
		dst[1] = (color >> 8) & 0xFF;
		dst[2] = (color) & 0xFF;
		dst[3] = (color >> 24) & 0xFF;
	}
	else
	{
		dst[0] = (color >> 24) & 0xFF;
		dst[1] = (color >> 16) & 0xFF;
		dst[2] = (color >> 8) & 0xFF;
		dst[3] = (color) & 0xFF;
	}
	// *(unsigned int *)dst = color;
}

int	close_window_escape(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

// int	mouse_move_handler(int x, int y)
// {
// 	static int	x_prev;
// 	static int	y_prev;
//
// 	printf("%f\n", atan2(y - y_prev, x - x_prev));
// 	x_prev = x;
// 	y_prev = y;
// 	return (0);
// }

int	render_next_frame(t_vars *vars)
{
	int			i;
	int			j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			my_mlx_pixel_put(&vars->data, j, i, create_trgb(1, 255, 0, 0));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}

void	clear(t_vars *vars)
{
	int			i;
	int			j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(&vars->data, j, i, create_trgb(1, 0, 0, 0));
			j++;
		}
		i++;
	}
}

// int	key_hook(int keycode)
// {
// 	ft_printf("%d\n", keycode);
// 	// if (keycode == UP)
// 	// {
// 	// 	vars->img.y -= 10;
// 	// 	draw_circle(vars, 0xFFFFFF);
// 	// }
// 	// else if (keycode == DOWN)
// 	// {
// 	// 	vars->img.y += 10;
// 	// 	draw_circle(vars, 0xFFFFFF);
// 	// }
// 	// else if(keycode == LEFT)
// 	// {
// 	// 	vars->img.x -= 10;
// 	// 	draw_circle(vars, 0xFFFFFF);
// 	// }
// 	// else if (keycode == RIGHT)
// 	// {
// 	// 	vars->img.x += 10;
// 	// 	draw_circle(vars, 0xFFFFFF);
// 	// }
// 	return (0);
// }

void	fill_helper(int ***fdf, int height, int width, int fd)
{
	int		i;
	int		j;
	char	**nums;
	char	*line;

	i = -1;
	while (++i < height)
	{
		(*fdf)[i] = (int *)malloc(width * sizeof(int));
		if (!((*fdf)[i]))
			free_exit(*fdf, i);
		line = get_next_line(fd);
		if (!line)
			free_exit(*fdf, i);
		nums = ft_split(line, ' ');
		if (!nums)
			free_exit(*fdf, i);
		j = -1;
		while (++j < width)
			(*fdf)[i][j] = atoi(nums[j]);
		free(line);
		free_split(nums);
	}
}

void	fill_matrix(int ***fdf, int height, int width, char *input)
{
	int		fd;

	if (height == 0 || width == 0)
		exit(0);
	fd = open(input, O_RDONLY);
	if (fd == -1)
		exit_error();
	*fdf = (int **)malloc(height * sizeof(int *));
	if (!(*fdf))
		exit_error();
	fill_helper(fdf, height, width, fd);
	close(fd);
}

void bresenham(t_vars *vars, int x1, int y1, int x2, int y2) 
{ 
    int	m_new;
    int	slope_error_new;
	int	x;
	int	y;
	int	color;
	
	x = x1;
	y = y1;
	if (vars->data.fdf[x / 100][y / 100] == 0)
		color = 0xFFFFFF;
	else
		color = 0xFF0000;
	if (abs(x2 - x1) > abs(y2 - y1))
	{
		m_new = 2 * (y2 - y1);
		slope_error_new = m_new - (x2 - x1);
		while (x < x2)
		{
			my_mlx_pixel_put(&vars->data, x, y, color);
			slope_error_new += m_new;
			if (slope_error_new >= 0) {
				y++;
				slope_error_new -= 2 * (x2 - x1);
			}
			x++;
		}
	}
	else
	{
		m_new = 2 * (x2 - x1);
		slope_error_new = m_new - (y2 - y1);
		while (y < y2)
		{
			my_mlx_pixel_put(&vars->data, x, y, color);
			slope_error_new += m_new;
			if (slope_error_new >= 0) {
				x++;
				slope_error_new -= 2 * (y2 - y1);
			}
			y++;
		}	
	}
}

void	draw(t_vars *vars, int height, int width)
{
	int	i;
	int	j;
	int	scale;
	
	scale = 50;
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			if (i + 1 < width)
				bresenham(vars, i * scale, j * scale, (i + 1) * scale, j * scale);
			if (j + 1 < height)
				bresenham(vars, i * scale, j * scale, i * scale, (j + 1) * scale);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_putstr_fd("Error: usage ./fdf file.fdf\n", 2);
		return (1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 4))
	{
		ft_putstr_fd("Error: usage ./fdf file.fdf\n", 2);
		return (1);
	}
	fill_matrix(&vars.data.fdf, get_height(argv[1]),
		get_width(argv[1]), argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FdF");
	vars.data.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel,
			&vars.data.line_length, &vars.data.endian);
	mlx_hook(vars.win, 2, 1L << 0, close_window_escape, &vars);
	mlx_hook(vars.win, 17, 1l << 17, close_window, &vars);
	draw(&vars, get_height(argv[1]), get_width(argv[1]));
	// mlx_hook(vars.win, 6, (1L << 6), mouse_move_handler, NULL);
	//mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	free_fdf(vars.data.fdf, get_height(argv[1]));
	return (0);
}
