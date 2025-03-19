/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:07:00 by marvin            #+#    #+#             */
/*   Updated: 2025/03/18 23:07:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b(t_lst **a, int counter, int size)
{
	int		i;
	t_lst	*temp;

	i = 0;
	temp = *a;
	while ((temp)->content != counter && ++i)
		temp = temp->next;
	if (i < size / 2)
	{
		while ((*a)->content != counter)
		{
			ra(a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while ((*a)->content != counter)
		{
			rra(a);
			ft_printf("rra\n");
		}
	}
}

static void	sort_3(t_lst **a, int size)
{
	if (size == 2)
	{
		if ((*a)->content == 1)
		{
			sa(a);
			ft_printf("sa\n");
		}
		return ;
	}
	if ((*a)->content == size - 1)
	{
		ra(a);
		ft_printf("ra\n");
	}
	else if ((*a)->next->content == size - 1)
	{
		rra(a);
		ft_printf("rra\n");
	}
	if ((*a)->content == size - 2)
	{
		sa(a);
		ft_printf("sa\n");
	}
}

void	sort_5(t_lst **a, t_lst **b, int size)
{
	int		counter;

	counter = 0;
	while (size - counter > 3)
	{
		push_b(a, counter, size);
		pb(a, b);
		ft_printf("pb\n");
		counter++;
	}
	sort_3(a, size);
	while (*b)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
	exit(0);
}
