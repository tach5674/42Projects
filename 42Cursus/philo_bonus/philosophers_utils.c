/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayel <mikayel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:22:30 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/15 13:07:38 by mikayel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	end_check(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->table->simulation_mutex);
// 	if (philo->table->simulation_over)
// 	{
// 		pthread_mutex_unlock(&philo->table->simulation_mutex);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&philo->table->simulation_mutex);
// 	return (0);
// }

void	print_msg(char *msg, t_table *table)
{
	// if (end_check(table))
	// 	return ;
	sem_wait(table->write_sem);
	printf("%d %d %s", get_time() - table->start_time, table->id, msg);
	sem_post(table->write_sem);
}
