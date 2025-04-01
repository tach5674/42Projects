/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:06:00 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/01 19:51:49 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	key_hook_rotations(int keycode, t_vars *vars)
{
	float	d;

	if (keycode == R_LEFT || keycode == R_RIGHT)
	{
		if (keycode == R_LEFT)
			d = 0.1;
		else
			d = -0.1;
		if (vars->data.x_key == 1)
		{
			vars->data.alpha += d;
			vars->data.needs_update = 1;
		}
		else if (vars->data.y_key == 1)
		{
			vars->data.betta += d;
			vars->data.needs_update = 1;
		}
		else if (vars->data.z_key == 1)
		{
			vars->data.gamma += d;
			vars->data.needs_update = 1;
		}
	}
}

static void	key_hook_projections(int keycode, t_vars *vars)
{
	if (keycode == 48 || keycode == 49 || keycode == 50 || keycode == 51 || keycode == 52)
	{
		if (keycode == 48)
			vars->data.projection = 0;
		else if (keycode == 49)
			vars->data.projection = 1;
		else if (keycode == 50)
			vars->data.projection = 2;
		else if (keycode == 51)
			vars->data.projection = 3;
		else if (keycode == 52)
			vars->data.projection = 4;
		vars->data.needs_update = 1;
		vars->data.gamma = 0;
		vars->data.alpha = 0;
		vars->data.betta = 0;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	key_hook_rotations(keycode, vars);
	key_hook_projections(keycode, vars);
	if (keycode == ESC_KEY)
		close_window_escape(vars);
	else if (keycode == UP)
		vars->data.targetOffsetY -= 10;
	else if (keycode == DOWN)
		vars->data.targetOffsetY += 10;
	else if (keycode == LEFT)
		vars->data.targetOffsetX -= 10;
	else if (keycode == RIGHT)
		vars->data.targetOffsetX += 10;
	else if (keycode == X)
		vars->data.x_key = 1;
	else if (keycode == Y)
		vars->data.y_key = 1;
	else if (keycode == Z)
		vars->data.z_key = 1;
	else if (keycode == 114)
	{
		if (vars->data.is_rotating)
			vars->data.is_rotating = 0;
		else
			vars->data.is_rotating = 1;
	}
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
		if (vars->data.target_scale > 1)
			vars->data.target_scale /= 1.05;
	}
	vars->data.targetOffsetX = x - image_x * vars->data.target_scale;
	vars->data.targetOffsetY = y - image_y * vars->data.target_scale;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 120)
		data->x_key = 0;
	else if (keycode == 121)
		data->y_key = 0;
	else if (keycode == 122)
		data->z_key = 0;
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	smooth_zoom(vars);
	smooth_translate(vars);
	if (vars->data.is_rotating == 1)
	{
		vars->data.gamma += 0.01;
		draw(vars, -1, -1);
	}
	if (vars->data.needs_update == 1)
	{
		draw(vars, -1, -1);
		vars->data.needs_update = 0;
	}
	return (0);
}
