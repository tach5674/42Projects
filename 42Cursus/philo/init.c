/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:46:34 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/08 17:58:58 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	fits_integer(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10 || (ft_strlen(argv[i]) == 10
				&& ft_strcmp(argv[i], "2147483647") > 0))
			return (0);
		i++;
	}
	return (1);
}

int	mutex_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&table->meal_mutex, NULL))
		return (0);
    if (pthread_mutex_init(&table->simulation_mutex, NULL))
    {
        pthread_mutex_destroy(&table->meal_mutex);
		return (0);
    }
	if (pthread_mutex_init(&table->write_mutex, NULL))
	{
		pthread_mutex_destroy(&table->meal_mutex);
        pthread_mutex_destroy(&table->simulation_mutex);
		return (0);
	}
	return (1);
}

void	philos_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n)
	{
		table->philos[i % table->n].id = i % table->n + 1;
		table->philos[i % table->n].has_eaten = 0;
		table->philos[i % table->n].left = &table->forks[i % table->n];
		table->philos[i % table->n].right = &table->forks[(i + 1) % table->n];
		table->philos[i % table->n].table = table;
		i++;
	}
}

int	fill_table(t_table *table, int argc, char *argv[])
{
	if (!fits_integer(argc, argv))
		return (0);
	table->simulation_over = 0;
	table->has_to_eat = -1;
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
	table->forks = malloc(table->n * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (0);
	table->philos = malloc(table->n * sizeof(t_philo));
	if (!table->philos)
	{
		free(table->forks);
		return (0);
	}
	if (!mutex_init(table))
	{
		free(table->forks);
		free(table->philos);
		return (0);
	}
	philos_init(table);
	return (1);
}
