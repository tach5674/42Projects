/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/18 13:42:59 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	kill_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n)
	{
		kill(table->pids[i], SIGKILL);
		i++;
	}
}

void	*main_monitor(void *t)
{
	t_table	*table;

	table = t;
	sem_wait(table->kill_sem);
	kill_all(table);
	free(table->pids);
	sem_post(table->kill_sem);
	return (NULL);
}

static void	simulation_start(t_table *table)
{
	init_sem(table);
	init_philos(table);
	sem_post(table->meal_sem);
	if (pthread_create(&table->monitor_thread, NULL, main_monitor, table))
		exit_error(table, "thread creation failed\n");
}

static void	simulation_end(t_table *table)
{
	int	status;

	while (waitpid(-1, &status, 0) != -1)
	{
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == EXIT_FAILURE)
			{
				kill_all(table);
				exit_error(table, "child process exited with error\n");
			}
		}
	}
	if (WEXITSTATUS(status) != SIGKILL)
		sem_post(table->kill_sem);
	if (pthread_join(table->monitor_thread, NULL))
		exit_error(table, "thread join failed\n");
	sem_close(table->forks_sem);
	sem_close(table->write_sem);
	sem_close(table->meal_sem);
	sem_close(table->sim_sem);
	sem_close(table->kill_sem);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	init(&table, argc, argv);
	simulation_start(&table);
	simulation_end(&table);
	return (0);
}
