/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:25:06 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/31 16:30:15 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_fraction(float x1, float x2, float x)
{
	if (x1 != x2)
		return ((x - x1) / (x2 - x1));
	return (0);
}

static float	choose_fraction(t_point *a, t_point *b, int x, int y)
{
	int		dx;
	int		dy;
	float	fraction;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (abs(dx) > abs(dy))
		fraction = get_fraction(x, b->x, a->x);
	else
		fraction = get_fraction(y, b->y, a->y);
	return (fraction);
}

int	get_color(t_data *data)
{
	int		red;
	int		green;
	int		blue;
	float	fraction;

	if (data->a.color == data->b.color)
		return (data->a.color);
	fraction = choose_fraction(&data->a, &data->b, data->x1, data->y1);
	red = get_r(data->a.color)
		+ (get_r(data->b.color) - get_r(data->a.color)) * fraction;
	green = get_g(data->a.color)
		+ (get_g(data->b.color) - get_g(data->a.color)) * fraction;
	blue = get_b(data->a.color)
		+ (get_b(data->b.color) - get_b(data->a.color)) * fraction;
	return (create_trgb(0, red, green, blue));
}
