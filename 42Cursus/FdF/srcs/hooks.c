/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:06:00 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/31 18:40:17 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
	// ft_printf("%i\n", keycode);
	if (keycode == ESC_KEY)
		close_window_escape(vars);
	else if (keycode == 44)
	{
		if (vars->data.x_key == 1)
		{
			vars->data.alpha += 0.1;
			vars->data.needs_update = 1;		
		}
		else if (vars->data.y_key == 1)
		{
			vars->data.betta += 0.1;
			vars->data.needs_update = 1;		
		}
		else if (vars->data.z_key == 1)
		{
			vars->data.gamma += 0.1;
			vars->data.needs_update = 1;		
		}
	}
	else if (keycode == 46)
	{
		if (vars->data.x_key == 1)
		{
			vars->data.alpha -= 0.1;
			vars->data.needs_update = 1;		
		}
		else if (vars->data.y_key == 1)
		{
			vars->data.betta -= 0.1;
			vars->data.needs_update = 1;		
		}
		else if (vars->data.z_key == 1)
		{
			vars->data.gamma -= 0.1;
			vars->data.needs_update = 1;		
		}
	}
	else if (keycode == UP)
		vars->data.targetOffsetY -= 10;
	else if (keycode == DOWN)
		vars->data.targetOffsetY += 10;
	else if (keycode == LEFT)
		vars->data.targetOffsetX -= 10;
	else if (keycode == RIGHT)
		vars->data.targetOffsetX += 10;
	else if (keycode == 120)
    	vars->data.x_key = 1;
	else if (keycode == 121)
		vars->data.y_key = 1;
	else if (keycode == 122)
		vars->data.z_key = 1;
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

int	key_release(int keycode, t_data *data)
{
	// if (data->x_key	== 0 || data->y_key == 0 || data->z_key == 0)
	// 	return (0);
	// printf("Key released: %d\n", keycode);
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
	if (vars->data.needs_update == 1)
	{
		draw(vars, -1, -1);
		vars->data.needs_update = 0;
	}
	return (0);
}
