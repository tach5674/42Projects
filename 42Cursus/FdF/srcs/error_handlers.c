/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:00:30 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/31 16:04:45 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	input_error(char *msg)
{
	perror(msg);
	exit(1);
}

void	fill_error(t_data *data, int n, int m)
{
	free_fdf(data->fdf, n);
	free_fdf(data->colors, m);
	perror("FdF");
	exit(1);
}

void	mlx_error(t_vars *vars)
{
	if (!vars->mlx)
	{
		fill_error(&vars->data, vars->data.height, vars->data.height);
	}
	else if (!vars->win)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		fill_error(&vars->data, vars->data.height, vars->data.height);
	}
	else if (!vars->data.img)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		fill_error(&vars->data, vars->data.height, vars->data.height);
	}
	else if (!vars->data.addr)
	{
		mlx_destroy_image(vars->mlx, vars->data.img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		fill_error(&vars->data, vars->data.height, vars->data.height);
	}
}
