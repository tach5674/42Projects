/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:07:05 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/18 11:05:49 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat(t_philo *self)
{
	print_msg(" is eating\n", self);
	usleep(self->time_to_eat);
	pthread_mutex_lock(&self->table->meal_mutex);
	self->has_eaten++;
	self->last_meal_time = get_time();
	pthread_mutex_unlock(&self->table->meal_mutex);
	pthread_mutex_unlock(self->left);
	pthread_mutex_unlock(self->right);
}

static void	philosopher_routine(t_philo *self, pthread_mutex_t *left,
		pthread_mutex_t *right)
{
	while (!end_check(self))
	{
		pthread_mutex_lock(left);
		print_msg(" has taken a fork\n", self);
		pthread_mutex_lock(right);
		print_msg(" has taken a fork\n", self);
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
		usleep(self->time_to_sleep);
		print_msg(" is thinking\n", self);
		if (end_check(self))
			return ;
		usleep((self->time_to_die - self->time_to_eat - self->time_to_sleep)
			/ 2);
	}
}

static void	wait_to_start(t_philo *self)
{
	while (1)
	{
		pthread_mutex_lock(&self->table->meal_mutex);
		if (self->table->start_time <= get_time())
		{
			pthread_mutex_unlock(&self->table->meal_mutex);
			return ;
		}
		pthread_mutex_unlock(&self->table->meal_mutex);
		usleep(100);
	}
}

void	*philosopher_thread(void *philo)
{
	t_philo	*self;

	self = philo;
	wait_to_start(self);
	if (self->table->n == 1)
	{
		pthread_mutex_lock(self->right);
		print_msg(" has taken a fork\n", self);
		while (!end_check(self))
			;
		pthread_mutex_unlock(self->right);
		return (NULL);
	}
	if (self->id % 2 == 0)
	{
		usleep(1000);
		philosopher_routine(self, self->right, self->left);
	}
	else
		philosopher_routine(self, self->left, self->right);
	return (NULL);
}
