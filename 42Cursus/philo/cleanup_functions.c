/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:37:31 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/08 14:13:09 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	destroy_mutexes(t_table *table, int n)
// {
// 	while (n--)
// 		pthread_mutex_destroy(&table->forks[n]);
// }

// void	free_philosophers(t_table *table, int n)
// {
// 	while (n--)
// 		free(&philosophers[n]);
// 	free(philosophers);
// }

// void	join_threads(pthread_t *threads, int n)
// {
// 	while (n--)
// 		pthread_join(threads[n], NULL);
// }