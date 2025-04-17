/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayel <mikayel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/17 20:18:01 by mikayel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_error(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(1);
}

static int	simulation_start(t_table *table)
{
	int	i;
	
	table->pids = malloc(table->n * sizeof(int));
	if (!table->pids)
		exit_error();
	table->forks_sem = sem_open("/forks", O_CREAT | O_EXCL, 0666, table->n);
	table->write_sem = sem_open("/write", O_CREAT | O_EXCL, 0666, 1);
	table->meal_sem = sem_open("/meal", O_CREAT | O_EXCL, 0666, 0);
	table->sim_sem = sem_open("/sim", O_CREAT | O_EXCL, 0666, 1);
	table->kill_sem = sem_open("/kill", O_CREAT | O_EXCL, 0666, 0);
	if (table->forks_sem == SEM_FAILED || table->write_sem == SEM_FAILED
		|| table->meal_sem == SEM_FAILED || table->sim_sem == SEM_FAILED || table->kill_sem == SEM_FAILED)
	{
		free(table->pids);
		exit_error();
	}
	if (sem_unlink("/forks") == -1 || sem_unlink("/write") == -1
		|| sem_unlink("/meal") == -1 || sem_unlink("/sim") == -1 || sem_unlink("/kill") == -1)
	{
		free(table->pids);
		exit_error();
	}
	i = 0;
	table->start_time = get_time() + 100;
	table->last_meal_time = table->start_time;
	while (i < table->n)
	{
		table->pids[i] = fork();
		if (table->pids[i] == -1)
		{
			exit_error();
		}
		if (table->pids[i] == 0)
		{
			table->id = i + 1;
			philosopher_process(table);
		}
		i++;
	}
	sem_post(table->meal_sem);
	if (pthread_create(&table->monitor_thread, NULL, main_monitor, table))
	{
		free(table->pids);
		exit_error();
	}
	return (1);
}

void	*main_monitor(void *t)
{
	t_table	*table;

	table= t;
	sem_wait(table->kill_sem);
	kill_all(table);
	free(table->pids);
	sem_post(table->kill_sem);
	return (NULL);
}

static int	simulation_end(t_table *table)
{
	int	status;

	while (waitpid(-1, &status, 0) != -1)
	{
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == EXIT_FAILURE)
			{
				kill_all(table);
				free(table->pids);
				exit_error(); 
			}
		}
	}
	if (WEXITSTATUS(status) != SIGKILL)
		sem_post(table->kill_sem);
	if (pthread_join(table->monitor_thread, NULL))
		exit_error();
	sem_close(table->forks_sem);
	sem_close(table->write_sem);
	sem_close(table->meal_sem);
	sem_close(table->sim_sem);
	sem_close(table->kill_sem);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_table	table;
	
	if (!init(&table, argc, argv))
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		return (EXIT_FAILURE);
	}
	if (!simulation_start(&table))
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		return (EXIT_FAILURE);
	}
	if (!simulation_end(&table))
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		return (EXIT_FAILURE);
	}
	return (0);
}
