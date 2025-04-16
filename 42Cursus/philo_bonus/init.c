/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:46:34 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/16 13:24:09 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	fill_table(t_table *table, int argc, char *argv[])
{
	if (!fits_integer(argc, argv))
		return (0);
	table->simulation_over = 0;
	table->has_to_eat = 0;
	table->start_check = 0;
	table->has_eaten = 0;
	table->exit_code = 0;
	table->n = ft_atoi(argv[1]);
	if (table->n <= 0)
		return (0);
	table->time_to_die = ft_atoi(argv[2]) * 1000;
	if (table->time_to_die <= 0)
		return (0);
	table->time_to_eat = ft_atoi(argv[3]) * 1000;
	if (table->time_to_eat <= 0)
		return (0);
	table->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (table->time_to_sleep <= 0)
		return (0);
	if (argc == 6)
	{
		table->has_to_eat = ft_atoi(argv[5]);
		if (table->has_to_eat <= 0)
			return (0);
	}
	return (1);
}

int	init(t_table *table, int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (0);
	if (!fill_table(table, argc, argv))
		return (0);
	return (1);
}
