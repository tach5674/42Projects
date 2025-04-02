/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:06:00 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/02 16:28:37 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	float	image_x;
	float	image_y;

	image_x = (x - vars->data.offset_x) / vars->data.scale;
	image_y = (y - vars->data.offset_y) / vars->data.scale;
	if (button == MOUSE_SCROLL_UP)
	{
		if (vars->data.scale < 100)
			vars->data.scale *= 1.05;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		if (vars->data.scale > 1)
			vars->data.scale /= 1.05;
	}
	vars->data.offset_x = x - image_x * vars->data.scale;
	vars->data.offset_y = y - image_y * vars->data.scale;
	vars->data.needs_update = 1;
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	if (vars->data.is_rotating_x == 1)
	{
		vars->data.alpha += 0.01;
		draw(vars, -1, -1);
	}
	if (vars->data.is_rotating_y == 1)
	{
		vars->data.betta += 0.01;
		draw(vars, -1, -1);
	}
	if (vars->data.is_rotating_z == 1)
	{
		vars->data.gamma += 0.01;
		draw(vars, -1, -1);
	}
	if (vars->data.needs_update == 1)
	{
		draw(vars, -1, -1);
		vars->data.needs_update = 0;
	}
	draw_instructions(vars);
	return (0);
}
