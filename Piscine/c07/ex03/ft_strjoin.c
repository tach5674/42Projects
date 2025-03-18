/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:12:49 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/19 17:20:42 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	str_len(char **strs, int size, char *sep)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	j = 0;
	while (sep[j])
		j++;
	return (count + j * (size - 1) + 1);
}

void	conc(char *str, int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (j < size)
	{
		k = 0;
		while (strs[j][k])
		{
			str[i] = strs[j][k];
			k++;
			i++;
		}
		k = 0;
		while (sep[k] && j + 1 < size)
		{
			str[i] = sep[k];
			i++;
			k++;
		}
		j++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;

	if (size == 0)
	{
		str = malloc(1);
		if (!str)
			return (0);
		*str = '\0';
		return (str);
	}
	len = str_len(strs, size, sep);
	str = malloc(len);
	if (!str)
		return (0);
	conc(str, size, strs, sep);
	return (str);
}
/*
int main(void)
{
	char *strs[3] = {"asf", "ifas", "dsada"};
	char *str = ft_strjoin(3, strs, " ");
	printf("%s \n", str);
	return (0);
}
*/
