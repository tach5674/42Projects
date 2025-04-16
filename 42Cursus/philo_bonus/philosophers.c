/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:07:05 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/16 14:02:55 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat(t_table *table)
{	
	print_msg(" is eating\n", table);
	if (end_check(table))
	{
		sem_post(table->forks_sem);
		sem_post(table->forks_sem);
		exit(table->exit_code);
	}
	usleep(table->time_to_eat);
	sem_wait(table->meal_sem);
	table->has_eaten++;
	table->last_meal_time = get_time();
	sem_post(table->meal_sem);
	sem_post(table->forks_sem);
	sem_post(table->forks_sem);
}

static void	philosopher_routine(t_table *table)
{
	int	time_to_die;
	
	sem_wait(table->meal_sem);
	time_to_die = table->time_to_die;
	sem_post(table->meal_sem);
	while (1)
	{
		sem_wait(table->forks_sem);
		print_msg(" has taken a fork\n", table);
		sem_wait(table->forks_sem);
		print_msg(" has taken a fork\n", table);
		eat(table);
		print_msg(" is sleeping\n", table);
		if (end_check(table))
			break ;
		usleep(table->time_to_sleep);
		print_msg(" is thinking\n", table);
		if (end_check(table))
			break ;
		usleep((time_to_die - table->time_to_eat - table->time_to_sleep) / 2);
	}
	exit(table->exit_code);
}

void	*philosopher_thread(void *t)
{
	t_table	*table;

	table = t;
	while (1)
	{
		sem_wait(table->meal_sem);
		if (table->has_eaten >= table->has_to_eat)
		{
			sem_wait(table->sim_sem);
			table->exit_code = FINISHED_EXIT_CODE;
			sem_post(table->sim_sem);
			return (NULL);
		}
		if (table->last_meal_time + table->time_to_die >= get_time())
		{
			sem_wait(table->sim_sem);
			table->exit_code = DEAD_EXIT_CODE;
			sem_post(table->sim_sem);
			return (NULL);
		}
		sem_post(table->meal_sem);
		usleep(1000);
	}
}

void	philosopher_process(t_table *table)
{
	if (table->n == 1)
	{
		
	}
	if (pthread_create(&table->thread, NULL, philosopher_thread, table))
		exit(ERROR_EXIT_CODE);
	philosopher_routine(table);
	exit(0);
}
