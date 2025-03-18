/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:31:15 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/18 23:47:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return ;
		i++;
	}
	free(arr);
	exit(0);
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
	is_sorted(unordered, argc - 1);
	sort_map(unordered, i);
	fill(&a, unordered, i);
	free(unordered);
	if (argc < 7)
		sort_5(&a, &b, argc - 1);
	bf_sort(&a, &b, i);
	free_stack(&a, &b);
	return (0);
}
