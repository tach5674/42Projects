/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:00:39 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/25 13:02:45 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_helper(t_vars *vars, int fd)
{
	int		i;
	int		j;
	char	**nums;
	char	*line;

	i = -1;
	while (++i < vars->data.height)
	{
		(vars->data.fdf)[i] = (int *)malloc(vars->data.width * sizeof(int));
		if (!((vars->data.fdf)[i]))
			exit_error(vars, i);
		line = get_next_line(fd);
		if (!line)
			exit_error(vars, i);
		nums = ft_split(line, ' ');
		if (!nums)
			exit_error(vars, i);
		j = -1;
		while (++j < vars->data.width)
			((vars->data.fdf))[i][j] = atoi(nums[j]);
		free(line);
		free_split(nums);
	}
}

void	fill_matrix(t_vars *vars, char *input)
{
	int		fd;

	if (vars->data.height == 0 || vars->data.width == 0)
		exit(0);
	fd = open(input, O_RDONLY);
	if (fd == -1)
		exit_error(vars, -1);
	vars->data.fdf = (int **)malloc(vars->data.height * sizeof(int *));
	if (!(vars->data.fdf))
		exit_error(vars, -1);
	fill_helper(vars, fd);
	close(fd);
}
