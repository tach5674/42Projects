/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:17:21 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/16 16:06:36 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	sort_helper(t_lst **a, t_lst **b, char *cmd)
{
	if (ft_strcmp(cmd, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(cmd, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(cmd, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(cmd, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(cmd, "ss\n") == 0)
	{
		sa(a);
		sb(b);
	}
	else
		return (1);
	return (0);
}

void	sort(t_lst **a, t_lst **b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (!cmd)
			return ;
		if (!sort_helper(a, b, cmd))
		{
			free(cmd);
			continue ;
		}
		if (ft_strcmp(cmd, "rr\n") == 0)
		{
			ra(a);
			rb(b);
		}
		else if (ft_strcmp(cmd, "rrr\n") == 0)
		{
			rra(a);
			rrb(b);
		}
		else
		{
			free_stack(a, b);
			exit_error();
		}
		free(cmd);
	}
}
