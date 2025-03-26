/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:50:42 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/25 12:56:46 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_fdf(int **fdf, int n)
{
	int	i;

	if (n == -1)
		return ;
	i = 0;
	while (i < n)
	{
		free(fdf[i]);
		i++;
	}
	free(fdf);
}

void	free_split(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	free_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

void	exit_error(t_vars *vars, int n)
{
	free_mlx(vars);
	free_fdf(vars->data.fdf, n);
	perror("FdF");
	exit(1);
}
