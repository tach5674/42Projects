/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:22:30 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/18 16:47:30 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	end_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->simulation_mutex);
	if (philo->table->simulation_over)
	{
		pthread_mutex_unlock(&philo->table->simulation_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->simulation_mutex);
	return (0);
}

void	print_msg(char *msg, t_philo *philo)
{
	if (end_check(philo))
		return ;
	pthread_mutex_lock(&philo->table->write_mutex);
	printf("%d %d%s", get_time() - philo->table->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->table->write_mutex);
}

void	ft_sleep(int time_to_sleep)
{
	int	current_time;

	current_time = get_time();
	while (get_time() - current_time < time_to_sleep / 1000)
		usleep(100);
}
