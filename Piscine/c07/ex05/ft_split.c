/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:53:57 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/22 13:40:54 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	str_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_cpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (src);
}

char	*apply_separators(char *str, char *charset, int *count)
{
	int		i;
	int		j;
	char	*s;

	s = malloc(str_len(str) + 1);
	if (!s)
		return (0);
	str_cpy(s, str);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (charset[j])
		{
			if (s[i] == charset[j])
			{
				s[i] = '\0';
				(*count)++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (s);
}

char	*fill(char *s, char **res, int count)
{
	int		i;

	i = 0;
	while (i < count + 1)
	{
		if (*s == '\0')
		{
			s++;
			count--;
			continue ;
		}
		res[i] = malloc(str_len(s) + 1);
		if (!(res[i]))
			return (0);
		s = str_cpy(res[i++], s);
		s++;
	}
	res[i] = 0;
	return ("");
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		count;
	char	*s;
	char	*temp;

	if (str == NULL || charset == NULL)
	{
		res = malloc(2 * sizeof(char *));
		*(++res) = 0;
		if (str != NULL)
			*(--res) = str;
		return (res);
	}
	count = 0;
	s = apply_separators(str, charset, &count);
	res = malloc((count + 2) * sizeof(char *));
	if (!res)
		return (0);
	temp = fill(s, res, count);
	if (!temp)
		return (0);
	return (res);
}

int	main(void)
{
	char	**arr;
	char	*str = "hel,]\0loy, how\0, a,re,y\0ou doi.ng";
	char	*charset = "\0";
	arr = ft_split(str, charset);
	while (*arr)
	{
		printf("%s \n", *arr);
		arr++;
	}
	return (0);
}

