/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:36:12 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/02 16:32:41 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_instructions(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 5, 80, 0xFFFFFF,
		"Isometric projection: key 0");
	mlx_string_put(vars->mlx, vars->win, 5, 60, 0xFFFFFF,
		"Parallel projections: keys 1-3");
	mlx_string_put(vars->mlx, vars->win, 5, 120, 0xFFFFFF,
		"TPP projection: keys 4");
	mlx_string_put(vars->mlx, vars->win, 5, 100, 0xFFFFFF,
		"Oblique projection: key 5");
	mlx_string_put(vars->mlx, vars->win, 5, 20, 0xFFFFFF,
		"Translate: arrow keys");
	mlx_string_put(vars->mlx, vars->win, 5, 40, 0xFFFFFF,
		"Zoom: mouse wheel up/down");
	mlx_string_put(vars->mlx, vars->win, 5, 140, 0xFFFFFF,
		"Rotations: x / y / z + < / >");
	mlx_string_put(vars->mlx, vars->win, 5, 160, 0xFFFFFF,
		"Auto rotations: q / w / e");
	mlx_string_put(vars->mlx, vars->win, 5, 180, 0xFFFFFF,
		"Exit: escape key");
}

void	close_window_escape(t_vars *vars)
{
	free_mlx(vars);
	free_fdf(vars->data.fdf, vars->data.height);
	free_fdf(vars->data.colors, vars->data.height);
	exit(0);
}

int	close_window(t_vars *vars)
{
	free_mlx(vars);
	free_fdf(vars->data.fdf, vars->data.height);
	free_fdf(vars->data.colors, vars->data.height);
	exit(0);
}
