/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:25:06 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/20 13:47:50 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	add_shade(int color, double distance)
{
	return (create_trgb(
			get_t(color),
			get_r(color) * distance,
			get_g(color) * distance,
			get_b(color) * distance));
}

int	get_opposite(int color)
{
	return (create_trgb(
			get_t(color),
			255 - get_r(color),
			255 - get_g(color),
			255 - get_b(color)));
}
