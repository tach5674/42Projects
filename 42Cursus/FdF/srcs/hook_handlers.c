/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:36:12 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/01 15:29:03 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	if (fabs(vars->data.offsetX - vars->data.targetOffsetX) < 0.5)
		vars->data.offsetX = vars->data.targetOffsetX;
	if (fabs(vars->data.offsetY - vars->data.targetOffsetY) < 0.5)
		vars->data.offsetY = vars->data.targetOffsetY;
	if (vars->data.offsetX != vars->data.targetOffsetX
		|| vars->data.offsetY != vars->data.targetOffsetY)
		vars->data.needs_update = 1;
	return (0);
}
