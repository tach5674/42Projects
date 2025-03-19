/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:42:42 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/19 16:10:20 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct n_list
{
	int				content;
	struct n_list	*next;
}	t_lst;

int		approximate_sqrt(int nb);
int		optimal_parameter(int n);
void	swap(int *a, int *b);
void	exit_error(void);
int		ft_strcmp(const char *s1, const char *s2);
void	map(int *unordered, int *ordered, int size);
void	sort_map(int *unordered, int size);
void	fill(t_lst **a, int *args, int size);
void	lstclear(t_lst **lst);
t_lst	*lstnew(int content);
t_lst	*lstlast(t_lst *lst);
void	free_stack(t_lst **a, t_lst **b);
void	sort_5(t_lst **a, t_lst **b, int size);
void	bf_sort(t_lst **a, t_lst **b, int size);

void	sa(t_lst **a);
void	sb(t_lst **b);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **a, t_lst **b);
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rra(t_lst **a);
void	rrb(t_lst **a);

#endif
