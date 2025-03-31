/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:00:02 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/31 19:14:11 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    rotate_z(t_data * data, t_point *a)
{
    int tmp_x;
    int tmp_y;
 
    tmp_x = a->x - data->width * data->scale / 2;
    tmp_y = a->y - data->height * data->scale / 2;
    a->x = tmp_x * cos(data->gamma) - tmp_y * sin(data->gamma);
    a->y = tmp_x * sin(data->gamma) + tmp_y * cos(data->gamma);
    a->x -= data->width * data->scale / 2;
    a->y -= data->height * data->scale / 2;
}

void    rotate_y(t_data * data, t_point *a)
{
    int tmp_x;
    // int tmp_z;

    tmp_x = a->x - data->width * data->scale / 2;
    // tmp_z = a->z - data->width * data->scale / 2;
    a->x = tmp_x * cos(data->betta) + a->z * sin(data->betta);
    a->z = a->z * cos(data->betta) - tmp_x * sin(data->betta);
   // a->x += data->width * data->scale / 2;
    // a->z += data->width * data->scale / 2;
}

void    rotate_x(t_data * data, t_point *a)
{
    int tmp_y;
    
    tmp_y = a->y - data->height * data->scale / 2;
    a->y = tmp_y * cos(data->alpha) - a->z * sin(data->alpha);
    a->z = tmp_y * sin(data->alpha) + a->z * cos(data->alpha);
    a->y += data->height * data->scale / 2;
}
