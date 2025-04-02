/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:04:38 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/02 15:05:19 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	tpp(t_data *data, t_point *a)
{
	int	d;

	d = (data->width + data->height) / 2 * 100;
	a->x = a->x * d / (-a->z + d + 1e-10);
	a->y = a->y * d / (-a->z + d + 1e-10);
}

void	parallel(t_point *a, int check)
{
	if (check == 1)
		a->x = a->z;
	else if (check == 2)
		a->y = a->z;
}

void	apply_projection(t_vars *vars, t_point *a)
{
	if (vars->data.projection == 1)
		parallel(a, 1);
	else if (vars->data.projection == 2)
		parallel(a, 2);
	else if (vars->data.projection == 3)
		parallel(a, 0);
	else if (vars->data.projection == 4)
		tpp(&vars->data, a);
	else if (vars->data.projection == 5)
		oblique(a);
	else
		isometric(a);
}
