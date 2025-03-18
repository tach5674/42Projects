/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:21 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/13 19:22:56 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_lst **a, t_lst **b)
{
	lstclear(a);
	lstclear(b);
}

int	approximate_sqrt(int nb)
{
	int		i;

	i = 1;
	while (i < nb / i)
		i++;
	return (i - 1);
}

int	optimal_parameter(int n)
{
	return (approximate_sqrt(n) * 3 / 2);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
