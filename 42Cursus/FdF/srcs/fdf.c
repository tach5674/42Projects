/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:40:59 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/20 16:43:25 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

// int	key_hook(int keycode)
// {
// 	ft_printf("%d\n", keycode);
// 	return (0);
// }
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
			my_mlx_pixel_put(&vars->img, j, i, create_trgb(1, 255, 0, 0));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.win, 2, 1L << 0, close_window_escape, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	// mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_hook(vars.win, 6, (1L << 6), mouse_move_handler, NULL);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
