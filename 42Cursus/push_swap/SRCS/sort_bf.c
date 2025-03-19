/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:47:11 by marvin            #+#    #+#             */
/*   Updated: 2025/03/18 23:47:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_b(t_lst **a, t_lst **b, int size)
{
	int		counter;

	counter = 0;
	while (counter < size)
	{
		if ((*a)->content <= counter)
		{
			pb(a, b);
			rb(b);
			ft_printf("pb\nrb\n");
			counter++;
		}
		else if ((*a)->content <= counter + optimal_parameter(size))
		{
			pb(a, b);
			ft_printf("pb\n");
			counter++;
		}
		else
		{
			ra(a);
			ft_printf("ra\n");
		}
	}
	return (counter);
}

static void	push_a(t_lst **a, t_lst **b, int i, int counter)
{
	if (i < counter / 2)
	{
		while ((*b)->content != counter)
		{
			rb(b);
			ft_printf("rb\n");
		}
	}
	else
	{
		while ((*b)->content != counter)
		{
			rrb(b);
			ft_printf("rrb\n");
		}
	}
	pa(a, b);
	ft_printf("pa\n");
}

void	bf_sort(t_lst **a, t_lst **b, int size)
{
	int		counter;
	int		i;
	t_lst	*temp;

	counter = push_b(a, b, size);
	while (--counter >= 0)
	{
		i = 0;
		temp = *b;
		while ((temp)->content != counter)
		{
			i++;
			temp = temp->next;
		}
		push_a(a, b, i, counter);
	}
}
