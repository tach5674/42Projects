/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:15:10 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/23 14:39:13 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char *container, char *buf)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!container || !buf)
		return (NULL);
	res = malloc(ft_strlen(container) + ft_strlen(buf) + 1);
	if (!res)
		return (NULL);
	while (container[i])
	{
		res[i] = container[i];
		i++;
	}
	while (buf[j])
	{
		res[i + j] = buf[j];
		j++;
	}
	res[i + j] = '\0';
	free(container);
	return (res);
}

void	gnl_strlcpy(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (i < size)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
}
