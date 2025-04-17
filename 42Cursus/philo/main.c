/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayel <mikayel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/17 20:18:16 by mikayel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	set_start_time(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&table->meal_mutex);
	table->start_time = get_time() + 100;
	while (++i < table->n)
		table->philos[i].last_meal_time = table->start_time;
	table->start_check = 1;
	pthread_mutex_unlock(&table->meal_mutex);
}

static int	simulation_start(t_table *table)
{
	int	i;

	i = -1;
	set_start_time(table);
	while (++i < table->n)
	{
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
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		return (EXIT_FAILURE);
	}
	if (!simulation_start(&table))
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		return (EXIT_FAILURE);
	}
	if (!simulation_end(&table))
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		return (EXIT_FAILURE);
	}
}
