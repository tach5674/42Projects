/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayel <mikayel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:37:31 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/09 15:48:26 by mikayel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(t_table *table, int n)
{
	while (n--)
		pthread_mutex_destroy(&table->forks[n]);
}

void	join_threads(t_table *table, int n)
{
	while (n--)
		pthread_join(table->philos[n].thread, NULL);
}
