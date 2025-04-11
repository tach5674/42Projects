/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:37:31 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/11 13:01:10 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(t_table *table, int n)
{
	while (n--)
		pthread_mutex_destroy(&table->forks[n]);
	pthread_mutex_destroy(&table->meal_mutex);
	pthread_mutex_destroy(&table->simulation_mutex);
	pthread_mutex_destroy(&table->write_mutex);
}

void	join_threads(t_table *table, int n)
{
	while (n--)
		pthread_join(table->philos[n].thread, NULL);
}
