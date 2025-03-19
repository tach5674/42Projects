/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:57:18 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/19 12:45:15 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	*res_free(char **res, char *str, int i)
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

static char	**splitter(char *str, int count)
{
	char			**res;
	int				i;
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

static int	helper(char **str, char **temp, int *count, int *i)
{
	char	c;

	if ((*str)[*i] == '\'' || (*str)[*i] == '"')
	{
		c = (*str)[*i];
		(*str)[(*i)++] = '\0';
		(*temp)++;
		while ((*str)[*i] && ((*str)[*i] != c))
			(*i)++;
		if ((*str)[*i])
		{
			*temp = *str + *i + 1;
			(*str)[*i] = '\0';
			(*count)++;
			return (0);
		}
		else
		{
			*temp = *str + *i;
			return (1);
		}
	}
	return (0);
}

char	**pipex_split(char const *s, char c, int i, int count)
{
	char			*str;
	char			*temp;

	if (c == '\0')
		return (one_string_case(s));
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	temp = str;
	while (str[i])
	{
		if (str[i] == c)
		{
			str[i] = '\0';
			if (ft_strchr(temp, '\0') > temp)
				count++;
			temp = str + i + 1;
		}
		else if (helper(&str, &temp, &count, &i) == 1)
			break ;
		i++;
	}
	if (ft_strchr(temp, '\0') > temp)
		count++;
	return (splitter(str, count));
}
