/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:29:08 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/19 13:44:31 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*res_free(char **res, char *str, unsigned int i)
{
	while (i--)
		free(res[i]);
	free(res);
	free(str);
	return (NULL);
}

static char	**one_string_case(const char *s)
{
	char	**res;

	if (ft_strlen(s) == 0)
	{
		res = malloc(sizeof(char *));
		if (!res)
			return (NULL);
		res[0] = NULL;
	}
	else
	{
		res = malloc(2 * sizeof(char *));
		if (!res)
			return (NULL);
		res[0] = ft_strdup(s);
		if (!res[0])
		{
			free(res);
			return (NULL);
		}
		res[1] = NULL;
	}
	return (res);
}

static char	**splitter(char *str, unsigned int count)
{
	char			**res;
	unsigned int	i;
	char			*temp;

	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (res_free(res, str, 0));
	i = 0;
	temp = str;
	while (count--)
	{
		while (!(*temp))
			temp++;
		res[i] = ft_strdup(temp);
		if (!res[i])
			return (res_free(res, str, i));
		temp = ft_strchr(temp, '\0');
		i++;
	}
	res[i] = NULL;
	free(str);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char			*str;
	char			*temp;
	unsigned int	count;

	if (c == '\0')
		return (one_string_case(s));
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	count = 0;
	temp = str;
	while (ft_strchr(temp, c))
	{
		*ft_strchr(temp, c) = '\0';
		if (ft_strlen(temp++) == 0)
			continue ;
		temp--;
		temp = ft_strchr(temp, '\0');
		temp++;
		count++;
	}
	if (*temp != '\0')
		count++;
	return (splitter(str, count));
}
