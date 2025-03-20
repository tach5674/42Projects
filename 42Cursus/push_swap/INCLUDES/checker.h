/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:57:11 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/19 17:48:03 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct n_list
{
	int				content;
	struct n_list	*next;
}	t_lst;

void	exit_error(void);
int		ft_strcmp(const char *s1, const char *s2);
void	fill(t_lst **a, int *args, int size);
void	lstclear(t_lst **lst);
t_lst	*lstnew(int content);
t_lst	*lstlast(t_lst *lst);
void	free_stack(t_lst **a, t_lst **b);
void	sort(t_lst **a, t_lst **b);

void	sa(t_lst **a);
void	sb(t_lst **b);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **a, t_lst **b);
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rra(t_lst **a);
void	rrb(t_lst **b);

#endif
