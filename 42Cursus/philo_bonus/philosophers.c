/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:07:05 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/18 16:46:38 by mzohraby         ###   ########.fr       */
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
		sem_close(table->forks_sem);
		sem_close(table->write_sem);
		sem_close(table->meal_sem);
		sem_close(table->sim_sem);
		sem_close(table->kill_sem);
		if (pthread_join(table->monitor_thread, NULL))
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	ft_sleep(table->time_to_eat);
	sem_wait(table->meal_sem);
	table->has_eaten++;
	table->last_meal_time = get_time();
	sem_post(table->meal_sem);
	sem_post(table->forks_sem);
	sem_post(table->forks_sem);
}

static void	philosopher_routine(t_table *table, int time_to_die)
{
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
		ft_sleep(table->time_to_sleep);
		print_msg(" is thinking\n", table);
		if (end_check(table))
			break ;
		ft_sleep((time_to_die - table->time_to_eat - table->time_to_sleep) / 2);
	}
	sem_close(table->forks_sem);
	sem_close(table->write_sem);
	sem_close(table->meal_sem);
	sem_close(table->sim_sem);
	sem_close(table->kill_sem);
	if (pthread_join(table->monitor_thread, NULL))
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

static void	*monitor_thread(void *t)
{
	t_table	*table;

	table = t;
	while (1)
	{
		sem_wait(table->meal_sem);
		if (table->has_to_eat && table->has_eaten >= table->has_to_eat)
		{
			sem_wait(table->sim_sem);
			table->simulation_over = 1;
			sem_post(table->sim_sem);
			sem_post(table->meal_sem);
			return (NULL);
		}
		if (get_time() - table->last_meal_time >= table->time_to_die / 1000)
		{
			sem_wait(table->sim_sem);
			sem_wait(table->write_sem);
			printf("%d %d %s", get_time() - table->start_time, table->id,
				"died\n");
			return (sem_post(table->kill_sem), NULL);
		}
		sem_post(table->meal_sem);
		usleep(1000);
	}
}

void	philosopher_process(t_table *table)
{
	int	time_to_die;

	free(table->pids);
	time_to_die = table->time_to_die;
	while (table->start_time > get_time())
		usleep(100);
	if (table->n == 1)
	{
		print_msg(" has taken a fork\n", table);
		ft_sleep(table->time_to_die);
		print_msg(" died\n", table);
		sem_close(table->forks_sem);
		sem_close(table->write_sem);
		sem_close(table->meal_sem);
		sem_close(table->sim_sem);
		sem_close(table->kill_sem);
		exit(EXIT_SUCCESS);
	}
	if (table->id % 2 == 0)
		ft_sleep(10000);
	if (pthread_create(&table->monitor_thread, NULL, monitor_thread, table))
		exit(EXIT_FAILURE);
	philosopher_routine(table, time_to_die);
	exit(EXIT_SUCCESS);
}
