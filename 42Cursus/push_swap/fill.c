/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:55:04 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/18 23:54:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void	map(int *unordered, int *ordered, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (unordered[i] != ordered[j])
			j++;
		unordered[i] = j;
		i++;
	}
	free(ordered);
}

void	sort_map(int *unordered, int size)
{
	int		i;
	int		j;
	int		*ordered;

	ordered = (int *)malloc((size) * sizeof(int));
	if (!ordered)
	{
		free(unordered);
		exit_error();
	}
	i = -1;
	while (++i < size)
		ordered[i] = unordered[i];
	j = -1;
	while (++j < size - 1)
	{
		i = 0;
		while (i < size - j - 1)
		{
			if (ordered[i] > ordered[i + 1])
				swap(&ordered[i], &ordered[i + 1]);
			i++;
		}
	}
	map(unordered, ordered, size);
}

void	fill(t_lst **a, int *args, int size)
{
	int		i;
	t_lst	*temp;

	i = 0;
	temp = lstnew(args[i++]);
	if (!temp)
	{
		free(args);
		free_stack(a, NULL);
		exit_error();
	}
	*a = temp;
	while (i < size)
	{
		temp->next = lstnew(args[i]);
		if (!(temp->next))
		{
			free(args);
			free_stack(a, NULL);
			exit_error();
		}
		temp = temp->next;
		i++;
	}
}
