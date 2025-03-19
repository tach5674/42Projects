/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:17:21 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/19 15:51:48 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_lst **a, t_lst **b)
{
	lstclear(a);
	lstclear(b);
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
