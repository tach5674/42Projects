/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dims.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:44 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/24 18:47:37 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count(char *line)
{
	char	**nums;
	int		count;
    int     i;
    
	if (!line)
		return (0);
	nums = ft_split(line, ' ');
	if (!nums)
    {
        free(line);
		exit_error();
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

int	get_height(char *input)
{
	int		fd;
	int		height;
    char    *line;
    
	fd = open(input, O_RDONLY);
	if (fd == -1)
		exit_error();
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

int	get_width(char *input)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		exit_error();
	line = get_next_line(fd);
	width = count(line);
	if (width == 0)
		return (0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && count(line) != width)
		{
            free(line);
			return (0);
		}
	}
	close(fd);
	return (width);
}
