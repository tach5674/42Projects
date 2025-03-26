/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:58 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/26 18:57:08 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_fraction(float x1, float x2, float x)
{
    if (x1 != x2)
        return ((x - x1) / (x2 - x1));
    return (0);
}

float	function(int x, int y, t_point *a, t_point *b)
{
    int   dx;
    int   dy;
    float fraction;

    dx = b->x - a->x;
    dy = b->y - a->y;
    if (abs(dx) > abs(dy))
        fraction = get_fraction(a->x, b->x, x);
    else
        fraction = get_fraction(a->y, b->y, y);
    return fraction;
}

int	get_color(t_point *a, t_point *b, float x1)
{
	int	red;
	int	green;
	int	blue;
	float fraction;

	if (a->color == b->color)
		return (a->color);
	fraction = get_fraction(x1, b->x, a->x);
	red = get_r(a->color) + (get_r(b->color) - get_r(a->color)) * fraction;
	green = get_g(a->color) + (get_g(b->color) - get_g(a->color)) * fraction;
	blue = get_b(a->color) + (get_b(b->color) - get_b(a->color)) * fraction;
	return (create_trgb(0, red, green, blue));
}

static void	slope_bigger_then_one(int dx, int dy, t_point *a, t_vars *vars)
{
	int	p;
	int	i;
	
	i = -1;
	p = 2 * abs(dx) - abs(dy);
	my_mlx_pixel_put(&vars->data, a->x, a->y,get_color(&vars->data.a, &vars->data.b, vars->data.x1));
	while (++i < abs(dy))
	{
		if (dy > 0)
			a->y += 1;
		else
			a->y -= 1;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				a->x += 1;
			else
				a->x -= 1;
			p = p + 2 * abs(dx) - 2 * abs(dy);
		}
		my_mlx_pixel_put(&vars->data, a->x, a->y, get_color(&vars->data.a, &vars->data.b, vars->data.x1));
	}
}

static void	slope_less_then_one(int dx, int dy, t_point *a, t_vars *vars)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(dy) - abs(dx);
	my_mlx_pixel_put(&vars->data, a->x, a->y, get_color(&vars->data.a, &vars->data.b, vars->data.x1));
	while (++i < abs(dx))
	{
		if (dx > 0)
			a->x += 1;
		else
			a->x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				a->y += 1;
			else
				a->y -= 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
		my_mlx_pixel_put(&vars->data, a->x, a->y, get_color(&vars->data.a, &vars->data.b, vars->data.x1));
	}
}

static void	isometric(t_point *a)
{
	int		temp;

	temp = a->x;
	a->x = (temp - a->y) * cos(0.6);
	a->y = (temp + a->y) * sin(0.6) - a->z;
}

static void	set_point(t_vars *vars, t_point *a, int i, int j)
{
	if (vars->data.fdf[j][i] > 0)
		a->color = create_trgb(0.1, 0, 255, 128);
	else
		a->color = create_trgb(0.1, 0, 205 , 205);
	a->x = i;
	a->y = j;
	a->z = vars->data.fdf[j][i];
	a->x *= vars->data.scale;
	a->y *= vars->data.scale;
	a->z *= vars->data.scale;
	isometric(a);
	a->x += vars->data.offsetX;
	a->y += vars->data.offsetY;
}

void	bresenham(t_vars *vars, int i, int j, int check)
{
	int		dx;
	int		dy;

	if (check)
	{
		set_point(vars, &vars->data.a, i, j);
		set_point(vars, &vars->data.b, i, j + 1);
	}
	else
	{
		set_point(vars, &vars->data.a, i, j);
		set_point(vars, &vars->data.b, i + 1, j);
	}
	dx = vars->data.b.x - vars->data.a.x;
	dy = vars->data.b.y - vars->data.a.y;
	vars->data.x1 = vars->data.a.x;
	if (abs(dx) > abs(dy))
		slope_less_then_one(dx, dy, &vars->data.a, vars);
	else
		slope_bigger_then_one(dx, dy, &vars->data.a, vars);
}
