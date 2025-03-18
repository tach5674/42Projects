/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:15:05 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/08 14:45:59 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reset(char **container)
{
	free(*container);
	*container = NULL;
	return (NULL);
}

static char	*extract(char **container, int i)
{
	char	*temp;
	char	*res;

	if (i < 0)
	{
		res = malloc(ft_strlen(*container) + 1);
		if (!res)
			return (NULL);
		ft_strlcpy(res, *container, ft_strlen(*container));
		free(*container);
		*container = NULL;
		return (res);
	}
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	ft_strlcpy(res, *container, i + 1);
	temp = malloc(ft_strlen(*container) - i);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, *container + i + 1, ft_strlen(*container) - i - 1);
	free(*container);
	*container = temp;
	return (res);
}

static char	*read_extract(char **container, int fd, int n)
{
	int			i;
	char		buf[BUFFER_SIZE + 1];

	while (n)
	{
		if ((*container)[0])
		{
			i = 0;
			while ((*container)[i] && (*container)[i] != '\n')
				i++;
			if (i != ft_strlen(*container))
				return (extract(container, i));
		}
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (reset(container));
		if (n == 0)
		{
			if ((*container)[0])
				return (extract(container, -1));
			return (reset(container));
		}
		buf[n] = '\0';
		*container = ft_strjoin(*container, buf);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*container;
	int			n;

	if (fd < 0)
	return (NULL);
	n = 1;
	if (!container)
	{
		container = malloc(1);
		if (!container)
			return (NULL);
		container[0] = '\0';
	}
	return (read_extract(&container, fd, n));
}
