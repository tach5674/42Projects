/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:11:37 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/31 19:20:03 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	isometric(t_point *a)
{
	int		temp;

	temp = a->x;
	a->x = (temp - a->y) * cos(0.6);
	a->y = (temp + a->y) * sin(0.6) - a->z;
}

void	set_point(t_vars *vars, t_point *a, int i, int j)
{
	a->color = vars->data.colors[j][i];
	a->x = i;
	a->y = j;
	a->z = vars->data.fdf[j][i];
	a->x *= vars->data.scale;
	a->y *= vars->data.scale;
	a->z *= vars->data.scale;
    if (vars->data.z_key == 1)
		rotate_z(&vars->data, a);
    if (vars->data.y_key == 1)
		rotate_y(&vars->data, a);
    if (vars->data.x_key == 1)
		rotate_x(&vars->data, a);
	isometric(a);
	a->x += vars->data.offsetX;
	a->y += vars->data.offsetY;
}

static int	in_window(t_point *a, t_point *b)
{
	if ((a->x <= 0 || a->x >= WIDTH || a->y <= 0 || a->y >= HEIGHT)
		&& (b->x <= 0 || b->x >= WIDTH || b->y <= 0 || b->y >= HEIGHT))
		return (1);
	return (0);
}

int	draw(t_vars *vars, int i, int j)
{
	clear(vars);
	while (++i < vars->data.width)
	{
		j = -1;
		while (++j < vars->data.height)
		{
			if (i + 1 < vars->data.width)
			{
				set_point(vars, &vars->data.a, i, j);
				set_point(vars, &vars->data.b, i + 1, j);
				if (!in_window(&vars->data.a, &vars->data.b))
					bresenham(vars);
			}
			if (j + 1 < vars->data.height)
			{
				set_point(vars, &vars->data.a, i, j);
				set_point(vars, &vars->data.b, i, j + 1);
				if (!in_window(&vars->data.a, &vars->data.b))
					bresenham(vars);
			}
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}
