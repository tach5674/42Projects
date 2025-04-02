/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:40:59 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/02 16:32:24 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_fdf(t_data *data, char *input)
{
	data->input = input;
	data->height = 0;
	data->width = -1;
	get_dims(data);
	data->scale = (WIDTH + HEIGHT) / (data->width + data->height) * 0.25;
	data->offset_x = WIDTH / 2 - (data->width * data->scale) / 4;
	data->offset_y = HEIGHT / 2 - (data->height * data->scale) / 4;
	data->needs_update = 1;
	data->alpha = 0;
	data->betta = 0;
	data->gamma = 0;
	data->x_key = 0;
	data->y_key = 0;
	data->z_key = 0;
	data->projection = 0;
	data->is_rotating_x = 0;
	data->is_rotating_y = 0;
	data->is_rotating_z = 0;
	fill_matrix(data, input);
}

static void	init_mlx(t_vars *vars, t_data *data)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		mlx_error(vars);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FdF");
	if (!vars->win)
		mlx_error(vars);
	data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!data->img)
		mlx_error(vars);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		mlx_error(vars);
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
	init_fdf(&vars.data, argv[1]);
	init_mlx(&vars, &vars.data);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1l << 17, close_window, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars.data);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
