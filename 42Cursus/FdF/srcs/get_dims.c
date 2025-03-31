/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dims.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:44 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/31 12:42:12 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count(char *line)
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
		input_error("INPUT");
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

void	get_dims(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->input, O_RDONLY);
	if (fd == -1)
		input_error("INPUT");
	line = get_next_line(fd);
	if (errno)
		input_error("INPUT");
	while (line)
	{
		data->height++;
		if (data->width == -1)
			data->width = count(line);
		else if (data->width != count(line))
		{
			ft_putstr_fd("INPUT: Invalid file\n", 2);
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
		if (errno)
			input_error("INPUT");
	}
	close(fd);
}
