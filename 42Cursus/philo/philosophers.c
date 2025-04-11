/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:07:05 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/11 14:18:31 by mzohraby         ###   ########.fr       */
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

static void	eat(t_philo *self)
{	
	print_msg(" is eating\n", self);
	usleep(self->table->time_to_eat);
	pthread_mutex_lock(&self->table->meal_mutex);
	self->has_eaten++;
	self->last_meal_time = get_time();
	pthread_mutex_unlock(&self->table->meal_mutex);
	pthread_mutex_unlock(self->left);
	pthread_mutex_unlock(self->right);
}

static void	philosopher_routine1(t_philo *self)
{
	while (!end_check(self))
	{
		pthread_mutex_lock(self->left);
		print_msg(" has taken a fork\n", self);
		pthread_mutex_lock(self->right);
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
		usleep(self->table->time_to_sleep);
		print_msg(" is thinking\n", self);
	}
}

static void	philosopher_routine2(t_philo *self)
{
	while (!end_check(self))
	{
		pthread_mutex_lock(self->right);
		print_msg(" has taken a fork\n", self);
		pthread_mutex_lock(self->left);
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
		pthread_mutex_unlock(self->right);
		return (NULL);
	}
	if (self->id % 2 == 0)
	{
		usleep(1000);
		philosopher_routine1(self);
	}
	else
	{
		philosopher_routine2(self);
	}
	return (NULL);
}
