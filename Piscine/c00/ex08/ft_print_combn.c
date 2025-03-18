/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:05:45 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/06 16:07:22 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_iter(char*nums, int i, int n)
{
	if (i > n)
	{
		write(1, nums, n + 1);
		if (nums[0] != '9' - n)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	if (i > 0)
	{
		nums[i] = nums[i - 1] + 1;
	}
	while (nums[i] <= '9' - n + i)
	{
		ft_iter(nums, i + 1, n);
		nums[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	nums[10];

	nums[0] = '0';
	ft_iter(nums, 0, n - 1);
}
