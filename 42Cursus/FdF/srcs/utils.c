/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:50:42 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/24 18:08:29 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_fdf(int **fdf, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		// ft_printf("%d\n", fdf[i][0]);
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

void	exit_error(void)
{
	perror("FdF");
	exit(1);
}

void	free_exit(int **fdf, int i)
{
	free_fdf(fdf, i);
	exit_error();
}
