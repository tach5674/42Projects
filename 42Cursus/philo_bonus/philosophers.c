/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayel <mikayel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:07:05 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/15 13:02:26 by mikayel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat(t_table *table)
{	
	print_msg(" is eating\n", table);
	usleep(table->time_to_eat);
	table->has_eaten++;
	table->last_meal_time = get_time();
	sem_post(table->forks_sem);
	sem_post(table->forks_sem);
}

static void	philosopher_routine(t_table *table)
{
	while (1)
	{
		sem_wait(table->forks_sem);
		print_msg(" has taken a fork\n", table);
		sem_wait(table->forks_sem);
		print_msg(" has taken a fork\n", table);
		eat(table);
		print_msg(" is sleeping\n", table);
		usleep(table->time_to_sleep);
		print_msg(" is thinking\n", table);
		usleep((table->time_to_die - table->time_to_eat - table->time_to_sleep) / 2);
	}
}

void	philosopher_process(t_table *table)
{
	if (table->n == 1)
	{
		sem_wait(table->sem);
	}
	philosopher_routine(table);
	exit(0);
}
