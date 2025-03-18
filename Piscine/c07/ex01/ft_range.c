/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:01:01 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/19 15:12:32 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	*ft_range(int min, int max)
{
	int		*res;
	int		i;

	if (min >= max)
		return (0);
	res = malloc((max - min) * sizeof(int));
	if (!res)
		return (0);
	i = 0;
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
/*
int	main(void)
{
	int		i;
	int 	min = 3;
	int		max = 9;
	int		*arr;
	arr = ft_range(min, max);
	i = -1;
	while (++i < max - min)
		printf("%d \n", arr[i]);
	return (0);
}
*/
