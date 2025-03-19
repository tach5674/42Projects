/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:34:10 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/19 16:13:32 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lst **a)
{
	t_lst	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *a;
	*a = temp->next;
	temp->next = NULL;
}

void	rrb(t_lst **b)
{
	t_lst	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *b;
	*b = temp->next;
	temp->next = NULL;
}

void	ra(t_lst **a)
{
	t_lst	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->next;
	lstlast(*a)->next = *a;
	(*a)->next = NULL;
	*a = temp;
}

void	rb(t_lst **b)
{
	t_lst	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b)->next;
	lstlast(*b)->next = *b;
	(*b)->next = NULL;
	*b = temp;
}
