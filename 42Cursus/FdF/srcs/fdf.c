/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:40:59 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/26 18:55:10 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window_escape(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		free_mlx(vars);
		free_fdf(vars->data.fdf, vars->data.height);
		exit(0);
	}
	return (0);
}

int	close_window(t_vars *vars)
{
	free_mlx(vars);
	free_fdf(vars->data.fdf, vars->data.height);
	exit(0);
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

void	draw(t_vars *vars)
{
	int	i;
	int	j;

	clear(vars);
	i = -1;
	while (++i < vars->data.width)
	{
		j = -1;
		while (++j < vars->data.height)
		{
			if (i + 1 < vars->data.width)
				bresenham(vars, i, j, 0);
			if (j + 1 < vars->data.height)
				bresenham(vars, i, j, 1);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
}

int	key_hook(int keycode, t_vars *vars)
{
	//ft_printf("%i\n", keycode);
	if (keycode == UP)
	{
		vars->data.offsetY -= 30;
		draw(vars);
	}
	else if (keycode == DOWN)
	{
		vars->data.offsetY += 30;
		draw(vars);
	}
	else if (keycode == LEFT)
	{
		vars->data.offsetX -= 30;
		draw(vars);
	}
	else if (keycode == RIGHT)
	{
		vars->data.offsetX += 30;
		draw(vars);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
	{
		vars->data.scale += 2;
		draw(vars);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		vars->data.scale -= 2;
		draw(vars);
	}
	return (0);
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
	vars.data.input = argv[1];
	vars.data.height = get_height(&vars);
	vars.data.width = get_width(&vars);
	fill_matrix(&vars, argv[1]);
	vars.data.scale = 30;
	vars.data.offsetX = (WIDTH - vars.data.width * vars.data.scale) / 2;
	vars.data.offsetY = (HEIGHT - vars.data.height * vars.data.scale) / 2;
	vars.data.mouse_pressed = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FdF");
	vars.data.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel,
			&vars.data.line_length, &vars.data.endian);
	mlx_hook(vars.win, 2, 1L << 0, close_window_escape, &vars);
	mlx_hook(vars.win, 17, 1l << 17, close_window, &vars);
	draw(&vars);
	// mlx_hook(vars.win, 6, (1L << 6), mouse_move_handler, NULL);
	//mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
