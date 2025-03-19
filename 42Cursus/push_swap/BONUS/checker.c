/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:56:49 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/19 15:17:41 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	checker_helper(char *argv[], int j, int i)
{
	char	*max;

	if (j == 1)
		max = "2147483648";
	else
		max = "2147483647";
	if (ft_strlen(argv[i] + j) > 10 || (ft_strlen(argv[i] + j) == 10
			&& ft_strcmp(argv[i] + j, max) > 0))
		exit_error();
	while (argv[i][j])
	{
		if (ft_isdigit(argv[i][j]) == 0)
			exit_error();
		j++;
	}
	j = 0;
	while (argv[j])
	{
		if (i != j && ft_strcmp(argv[i], argv[j]) == 0)
			exit_error();
		j++;
	}
}

static void	checker(char *argv[])
{
	int		i;
	int		j;

	i = -1;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) == 0)
			exit_error();
		j = 0;
		if (argv[i][0] == '-')
		{
			if (ft_strlen(argv[i]) > 1)
				j++;
			else
				exit_error();
		}
		if (argv[i][j] == '0' && ft_strlen(argv[i]) > 1)
			exit_error();
		checker_helper(argv, j, i);
	}
}

static int	is_sorted(t_lst **a, t_lst **b)
{
	t_lst	*temp;

	if (*b)
		return (0);
	temp = *a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_lst	*a;
	t_lst	*b;
	int		*unordered;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	checker(argv + 1);
	unordered = (int *)malloc((argc - 1) * sizeof(int));
	if (!unordered)
		return (1);
	i = -1;
	while (++i < argc - 1)
		unordered[i] = ft_atoi(argv[i + 1]);
	fill(&a, unordered, i);
	free(unordered);
	sort(&a, &b);
	if (is_sorted(&a, &b) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a, &b);
	return (0);
}
