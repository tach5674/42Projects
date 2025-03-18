/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:34:10 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/18 23:50:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lst **a, t_lst **b)
{
	t_lst	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = lstnew(lstlast(*a)->content);
	if (!temp)
	{
		free_stack(a, b);
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	temp->next = *a;
	*a = temp;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}

void	rrb(t_lst **b, t_lst **a)
{
	t_lst	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = lstnew(lstlast(*b)->content);
	if (!temp)
	{
		free_stack(a, b);
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	temp->next = *b;
	*b = temp;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
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
