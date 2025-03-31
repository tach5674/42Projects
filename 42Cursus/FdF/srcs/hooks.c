/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:06:00 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/31 16:17:19 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == UP)
		vars->data.targetOffsetY -= 10;
	else if (keycode == DOWN)
		vars->data.targetOffsetY += 10;
	else if (keycode == LEFT)
		vars->data.targetOffsetX -= 10;
	else if (keycode == RIGHT)
		vars->data.targetOffsetX += 10;
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	float	image_x;
	float	image_y;

	image_x = (x - vars->data.offsetX) / vars->data.scale;
	image_y = (y - vars->data.offsetY) / vars->data.scale;
	if (button == MOUSE_SCROLL_UP)
	{
		if (vars->data.target_scale < 100)
			vars->data.target_scale *= 1.05;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		if (vars->data.target_scale > 0.1)
			vars->data.target_scale /= 1.05;
	}
	vars->data.targetOffsetX = x - image_x * vars->data.target_scale;
	vars->data.targetOffsetY = y - image_y * vars->data.target_scale;
	return (0);
}

int	smooth_zoom(t_vars *vars)
{
	vars->data.scale = vars->data.scale * 0.2 + vars->data.target_scale * 0.8;
	if (fabs(vars->data.scale - vars->data.target_scale) < 0.01)
		vars->data.scale = vars->data.target_scale;
	if (vars->data.scale != vars->data.target_scale)
		vars->data.needs_update = 1;
	return (0);
}

int	smooth_translate(t_vars *vars)
{
	vars->data.offsetX = vars->data.offsetX * 0.2
		+ vars->data.targetOffsetX * 0.8;
	vars->data.offsetY = vars->data.offsetY * 0.2
		+ vars->data.targetOffsetY * 0.8;
	if (fabs(vars->data.offsetX - vars->data.targetOffsetX) < 0.1)
		vars->data.offsetX = vars->data.targetOffsetX;
	if (fabs(vars->data.offsetY - vars->data.targetOffsetY) < 0.1)
		vars->data.offsetY = vars->data.targetOffsetY;
	if (vars->data.offsetX != vars->data.targetOffsetX
		|| vars->data.offsetY != vars->data.targetOffsetY)
		vars->data.needs_update = 1;
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	smooth_zoom(vars);
	smooth_translate(vars);
	if (vars->data.needs_update == 1)
	{
		draw(vars, -1, -1);
		vars->data.needs_update = 0;
	}
	return (0);
}
