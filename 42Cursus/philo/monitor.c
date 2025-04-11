/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:10:49 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/11 13:33:45 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_if_dead(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->meal_mutex);
	while (i < table->n)
	{
		if (get_time() - table->philos[i].last_meal_time >= table->time_to_die
			/ 1000)
		{
			pthread_mutex_unlock(&table->meal_mutex);
			return (i % table->n + 1);
		}
		i++;
	}
	pthread_mutex_unlock(&table->meal_mutex);
	return (0);
}

static int	check_if_finished(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->meal_mutex);
	while (i < table->n)
	{
		if (table->philos[i].has_eaten < table->has_to_eat)
		{
			pthread_mutex_unlock(&table->meal_mutex);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&table->meal_mutex);
	return (1);
}

static void	change_simulation_state(t_table *table)
{
	pthread_mutex_lock(&table->simulation_mutex);
	table->simulation_over = 1;
	pthread_mutex_unlock(&table->simulation_mutex);
}

void	*monitor(void *t)
{
	t_table	*table;
	int		id;

	table = t;
	while (1)
	{
		id = check_if_dead(table);
		if (id)
		{
			change_simulation_state(table);
			pthread_mutex_lock(&table->write_mutex);
			printf("%d %d %s", get_time() - table->start_time, id, "died\n");
			pthread_mutex_unlock(&table->write_mutex);
			return (NULL);
		}
		if (table->has_to_eat)
		{
			id = check_if_finished(table);
			if (id)
				return (change_simulation_state(table), NULL);
		}
		usleep(1000);
	}
}
