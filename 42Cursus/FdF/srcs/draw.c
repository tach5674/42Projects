/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:11:37 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/01 19:43:07 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	oblique(t_point *a)
{
	a->x = a->x + a->z / 2 * cos(0.8);
	a->y = a->y + a->z / 2 * cos(0.8);
}

void	TPP(t_data *data, t_point *a)
{
	int	d;

	d = (data->width + data->height) / 2 * 100;
	
	a->x = a->x * d / (-a->z + d + 1e-10);
	a->y = a->y * d / (-a->z + d + 1e-10);
}

void	barrel_distortion(t_point *a)
{
    int r;
	int	k;

	k = 0.8;
	r = sqrt(a->x * a->x + a->y * a->y);
    a->x = a->x * (1 + k * r * r);
    a->y = a->y * (1 + k * r * r);
}

void	perspective(t_data *data, t_point *a)
{
	a->x = a->x / (2 + a->z / data->scale * 0.1);
	a-> y = a->y / (2 + a->z / data->scale * 0.1);
}

void	apply_projection(t_vars *vars, t_point *a)
{
	if (vars->data.projection == 1)
		barrel_distortion(a);
	else if (vars->data.projection == 2)
		TPP(&vars->data, a);
	else if (vars->data.projection == 3)
		oblique(a);
	else if (vars->data.projection == 4)
		perspective(&vars->data, a);
	else
		isometric(a);
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
	rotate_x(&vars->data, a);
	rotate_y(&vars->data, a);
	rotate_z(&vars->data, a);
	apply_projection(vars, a);
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
