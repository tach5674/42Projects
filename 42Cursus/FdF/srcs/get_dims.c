/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dims.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:44 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/25 12:58:39 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count(t_vars *vars, char *line)
{
	char	**nums;
	int		count;
	int		i;

	if (!line)
		return (0);
	nums = ft_split(line, ' ');
	if (!nums)
	{
		free(line);
		exit_error(vars, -1);
	}
	count = 0;
	i = 0;
	while (nums[i])
	{
		if (ft_strncmp(nums[i], "\n", 1))
			count++;
		i++;
	}
	free_split(nums);
	return (count);
}

int	get_height(t_vars *vars)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(vars->data.input, O_RDONLY);
	if (fd == -1)
		exit_error(vars, -1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(t_vars *vars)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(vars->data.input, O_RDONLY);
	if (fd == -1)
		exit_error(vars, -1);
	line = get_next_line(fd);
	width = count(vars, line);
	if (width == 0)
		return (0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && count(vars, line) != width)
		{
			free(line);
			return (0);
		}
	}
	close(fd);
	return (width);
}
