/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:49:14 by marvin            #+#    #+#             */
/*   Updated: 2025/03/18 23:49:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_lst **a, t_lst **b)
{
	t_lst	*temp;

	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
}

void	pb(t_lst **a, t_lst **b)
{
	t_lst	*temp;

	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
}

void	sa(t_lst **a)
{
	t_lst	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
}

void	sb(t_lst **b)
{
	t_lst	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
}
