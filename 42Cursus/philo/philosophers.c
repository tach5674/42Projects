/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayel <mikayel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:07:05 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/09 16:00:35 by mikayel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	end_check(t_philo *philo)
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

static void	print_msg(char *msg, t_philo *philo)
{
	if (end_check(philo))
		return ;
	pthread_mutex_lock(&philo->table->write_mutex);
	printf("%d %d %s", get_time() - philo->table->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->table->write_mutex);
}

static void eat(t_philo *self)
{
    usleep(self->table->time_to_eat);
    pthread_mutex_lock(&self->table->meal_mutex);
    self->has_eaten++;
    self->last_meal_time = get_time();
    pthread_mutex_unlock(&self->table->meal_mutex);
    pthread_mutex_unlock(self->left);
    pthread_mutex_unlock(self->right);
}

static void	philosopher_routine(t_philo *self)
{
	while (1)
	{
		pthread_mutex_lock(self->left);
		print_msg(" has taken a fork\n", self);
		pthread_mutex_lock(self->right);
		print_msg(" has taken a fork\n", self);
		print_msg(" is eating\n", self);
		if (end_check(self))
		{
			pthread_mutex_unlock(self->left);
			pthread_mutex_unlock(self->right);
			return ;
		}
        eat(self);
		print_msg(" is sleeping\n", self);
		if (end_check(self))
			return ;
		usleep(self->table->time_to_sleep);
		print_msg(" is thinking\n", self);
	}
}

void	*philosopher_thread(void *philo)
{
	t_philo	*self;
	
	self = philo;
	
    if (self->table->n == 1)
    {
        pthread_mutex_lock(self->right);
        print_msg(" has taken a fork\n", self);
        while (!end_check(self))
            ;
        return (NULL);  
    }
	if (self->id % 2)
		usleep(1000);
	philosopher_routine(self);
	return (NULL);
}
