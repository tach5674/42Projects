/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:50:42 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/31 16:10:44 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WIDTH || y <= 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window_escape(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		free_mlx(vars);
		free_fdf(vars->data.fdf, vars->data.height);
		free_fdf(vars->data.colors, vars->data.height);
		exit(0);
	}
	return (0);
}

int	close_window(t_vars *vars)
{
	free_mlx(vars);
	free_fdf(vars->data.fdf, vars->data.height);
	free_fdf(vars->data.colors, vars->data.height);
	exit(0);
}
