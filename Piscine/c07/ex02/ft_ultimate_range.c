/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:27:11 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/19 15:29:54 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (!(*range))
		return (-1);
	i = -1;
	while (++i < max - min)
		(*range)[i] = min + i;
	return (i);
}
/*
int main(void)
{
	int **res;
	res = malloc(sizeof(int *));
	int min = 9;
	int max = 9;
	int i = -1;
	printf("%d \n", ft_ultimate_range(res, min, max));
	while (++i < max - min)
		printf("%d \n", (*res)[i]);
	return (0);
}
*/
