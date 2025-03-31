/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:00:39 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/31 16:14:55 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_num_color(t_data *data, char **nums, int i, int j)
{
	char	**num_color;
	int		color;

	while (++j < data->width)
	{
		((data->fdf))[i][j] = atoi(nums[j]);
		num_color = ft_split(nums[j], ',');
		if (!num_color)
			fill_error(data, i + 1, i + 1);
		((data->fdf))[i][j] = atoi(num_color[0]);
		if (num_color[1] && ft_strchr(num_color[1], '\n'))
			*ft_strchr(num_color[1], '\n') = '\0';
		color = atohex(num_color[1]);
		if (color == -1)
		{
			if (data->fdf[i][j] != 0)
				((data->colors))[i][j] = create_trgb(1, 0, 250, 250);
			else
				((data->colors))[i][j] = create_trgb(1, 0, 150, 150);
		}
		else
			((data->colors))[i][j] = color;
		free_split(num_color);
	}
}

static void	fill_helper(t_data *data, int fd)
{
	int		i;
	char	**nums;
	char	*line;

	i = -1;
	while (++i < data->height)
	{
		(data->fdf)[i] = (int *)malloc(data->width * sizeof(int));
		if (!((data->fdf)[i]))
			fill_error(data, i, i);
		(data->colors)[i] = (int *)malloc(data->width * sizeof(int));
		if (!((data->colors)[i]))
			fill_error(data, i + 1, i);
		line = get_next_line(fd);
		if (!line)
			fill_error(data, i + 1, i + 1);
		nums = ft_split(line, ' ');
		if (!nums)
			fill_error(data, i + 1, i + 1);
		set_num_color(data, nums, i, -1);
		free(line);
		free_split(nums);
	}
}

void	fill_matrix(t_data *data, char *input)
{
	int		fd;

	if (data->height == 0 || data->width == 0)
		exit(0);
	fd = open(input, O_RDONLY);
	if (fd == -1)
		fill_error(data, -1, -1);
	data->fdf = (int **)malloc(data->height * sizeof(int *));
	if (!(data->fdf))
		fill_error(data, -1, -1);
	data->colors = (int **)malloc(data->height * sizeof(int *));
	if (!(data->colors))
		fill_error(data, 0, -1);
	fill_helper(data, fd);
	close(fd);
}
