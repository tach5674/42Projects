/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:37:31 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/06 13:46:56 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(pthread_mutex_t **mutexes, int n)
{
	while (n--)
		pthread_mutex_destroy(mutexes[n]);
	free(mutexes);
}

void	free_philosophers(t_philosopher **philosophers, int n)
{
	while (n--)
		free(&philosophers[n]);
	free(philosophers);
}

void	join_threads(pthread_t *threads, int n)
{
	while (n--)
		pthread_join(threads[n], NULL);
}