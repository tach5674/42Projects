/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/11 13:56:09 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	simulation_start(t_table *table)
{
	int	i;

	i = -1;
	table->start_time = get_time();
	while (++i < table->n)
	{
		table->philos[i].last_meal_time = get_time();
		if (pthread_create(&(table->philos[i].thread), NULL, philosopher_thread,
				&table->philos[i]))
		{
			destroy_mutexes(table, table->n);
			join_threads(table, i);
			free(table->forks);
			free(table->philos);
			return (0);
		}
	}
	if (pthread_create(&(table->death_monitor), NULL, monitor, table))
	{
		destroy_mutexes(table, table->n);
		join_threads(table, table->n);
		free(table->forks);
		return (free(table->philos), 0);
	}
	return (1);
}

static int	simulation_end(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_join(table->death_monitor, NULL))
	{
		destroy_mutexes(table, table->n);
		free(table->forks);
		free(table->philos);
		return (0);
	}
	while (i < table->n)
	{
		if (pthread_join(table->philos[i].thread, NULL))
		{
			destroy_mutexes(table, table->n);
			free(table->forks);
			free(table->philos);
			return (0);
		}
		i++;
	}
	destroy_mutexes(table, table->n);
	free(table->forks);
	free(table->philos);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (!init(&table, argc, argv))
		return (EXIT_FAILURE);
	if (!simulation_start(&table))
		return (EXIT_FAILURE);
	if (!simulation_end(&table))
		return (EXIT_FAILURE);
}
