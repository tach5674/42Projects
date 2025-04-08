/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/08 18:41:08 by mzohraby         ###   ########.fr       */
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

void print_msg(char *msg, t_philo *philo)
{
	if (end_check(philo))
		return ;
	pthread_mutex_lock(&philo->table->write_mutex);
	ft_putnbr_fd(get_time() - philo->table->start_time, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putstr_fd(msg, 1);
	pthread_mutex_unlock(&philo->table->write_mutex);
}

void	philosopher_odd(t_philo *self)
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
		usleep(self->table->time_to_eat);
		pthread_mutex_lock(&self->table->meal_mutex);
		self->has_eaten++;
		self->last_meal_time = get_time();
		pthread_mutex_unlock(&self->table->meal_mutex);
		pthread_mutex_unlock(self->left);
		pthread_mutex_unlock(self->right);
		print_msg(" is sleeping\n", self);
		if (end_check(self))
			return ;
		usleep(self->table->time_to_sleep);
		print_msg(" is thinking\n", self);
	}
}

void	philosopher_even(t_philo *self)
{
	while (1)
	{
		pthread_mutex_lock(self->right);
		print_msg(" has taken a fork\n", self);
		pthread_mutex_lock(self->left);
		print_msg(" has taken a fork\n", self);
		print_msg(" is eating\n", self);
		if (end_check(self))
		{
			pthread_mutex_unlock(self->left);
			pthread_mutex_unlock(self->right);
			return ;
		}
		usleep(self->table->time_to_eat);
		pthread_mutex_lock(&self->table->meal_mutex);
		self->has_eaten++;
		self->last_meal_time = get_time();
		pthread_mutex_unlock(&self->table->meal_mutex);
		pthread_mutex_unlock(self->left);
		pthread_mutex_unlock(self->right);
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
	
	if (self->id % 2)	
		philosopher_odd(self);
	else
		philosopher_even(self);
	return (NULL);
}

void	*one_philosopher_thread(void *philo)
{
	t_philo	*self;
	
	self = philo;
	pthread_mutex_lock(self->right);
	print_msg(" has taken a fork\n", self);
	while (!end_check(self))
		;
	return (NULL);
}

int	check_if_dead(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n)
	{	
		pthread_mutex_unlock(&table->write_mutex);
		if (get_time() - table->philos[i].last_meal_time >= table->time_to_die / 1000)
			return (i % table->n + 1);
		i++; 
	}
	return (0);
}

int	check_if_finished(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n)
	{
		if (table->philos[i].has_eaten < table->has_to_eat)
			return (0);
		i++; 
	}
	return (1);
}

void	*death_monitor(void *t)
{
	t_table	*table;
	int		id;
	
	table = t;
	while (1)
	{
		pthread_mutex_lock(&table->meal_mutex);
		id = check_if_dead(table);
		pthread_mutex_unlock(&table->meal_mutex);
		if (id)
		{
			pthread_mutex_lock(&table->simulation_mutex);
			table->simulation_over = 1;
			pthread_mutex_unlock(&table->simulation_mutex);
			pthread_mutex_lock(&table->write_mutex);
			ft_putnbr_fd(get_time() - table->start_time, 1);
			ft_putstr_fd(" ", 1);
			ft_putnbr_fd(id, 1);
			ft_putstr_fd(" died\n", 1);
			pthread_mutex_unlock(&table->write_mutex);
			return (NULL);
		}
		// id = check_if_finished(table);
		// if (id)
		// {
		// 	pthread_mutex_lock(&table->simulation_mutex);
		// 	table->simulation_over = 1;
		// 	pthread_mutex_unlock(&table->simulation_mutex);
		// 	return (NULL);
		// }
		usleep(1000);
	}
}

int	simulation_start(t_table *table)
{
	int	i;

	if (table->n == 1)
	{
		table->start_time = get_time();
		table->philos[0].last_meal_time = get_time();
		if (pthread_create(&(table->philos[0].thread), NULL, one_philosopher_thread, &table->philos[0]))
		{
			free(table->forks);
			free(table->philos);
			return (0);
		}
	}
	else
	{
		i = 0;
		while (i < table->n)
		{
			table->start_time = get_time();
			table->philos[i].last_meal_time = get_time();
			if (pthread_create(&(table->philos[i].thread), NULL, philosopher_thread, &table->philos[i]))
			{
				free(table->forks);
				free(table->philos);
				return (0);
			}	
			i++;
		}
	}
	if (pthread_create(&(table->death_monitor), NULL, death_monitor, table))
	{
		free(table->forks);
		free(table->philos);
		return (0);
	}	
	return (1);
}

int	simulation_end(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->death_monitor, NULL);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_table	table;
	
	if (!init(&table, argc, argv))
		return (EXIT_FAILURE);
	if (!simulation_start(&table))
		return (EXIT_FAILURE);
	if (!simulation_end(&table))
		return (EXIT_FAILURE);
}
