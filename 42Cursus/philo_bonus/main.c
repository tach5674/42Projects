/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/16 14:13:13 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	simulation_start(t_table *table)
{
	int	i;
	
	table->pids = malloc(table->n * sizeof(int));
	if (!table)
		return (0);
	table->forks_sem = sem_open("/forks", O_CREAT, 0666, table->n);
	if (!table->forks_sem)
	{
		free(table);
		return (0);	
	}
	table->write_sem = sem_open("/write", O_CREAT, 0666, 1);
	if (!table->write_sem)
	{
		free(table);
		return (0);	
	}
	table->write_sem = sem_open("/meal", O_CREAT, 0666, 1);
	if (!table->meal_sem)
	{
		free(table);
		return (0);	
	}
	table->write_sem = sem_open("/sim", O_CREAT, 0666, 1);
	if (!table->sim_sem)
	{
		free(table);
		return (0);	
	}
	i = 0;
	while (i < table->n)
	{
		table->pids[i] = fork();
		if (table->pids[i] == -1)
			return (0);
		if (table->pids[i] == 0)
		{
			table->id = i + 1;
			table->start_time = get_time();
			table->last_meal_time = get_time();
			philosopher_process(table);
		}
		i++;
	}
	sem_close(table->forks_sem);
	sem_close(table->write_sem);
	sem_close(table->meal_sem);
	sem_close(table->sim_sem);
	return (1);
}

void	kill_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n)
	{
		if (i != table->id - 1)
			kill(table->pids[i], SIGKILL);
	}
}

void	*waiter_thread(void *t)
{
	t_table *table;
	int		status;
	
	table = t;
	waitpid(table->pids[table->id - 1], &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == DEAD_EXIT_CODE)
		{
			kill_all(table);
			print_msg(" died\n", table);
		}
		else if (WEXITSTATUS(status) == FINISHED_EXIT_CODE)
		{
			sem_wait(table->meal_sem);
			table->has_eaten++;
			sem_post(table->meal_sem);
		}
		else if (WEXITSTATUS(status) == ERROR_EXIT_CODE)
		{
			write(2, "Error\n", ft_strlen("Error\n"));
			exit(1);
		}
	}
	exit(0);
}

void	*monitor_thread(void *t)
{
	t_table	*table;
	
	table = t;
	while (1)
	{
		sem_wait(table->meal_sem);
		if (table->has_eaten == table->n)
		{
			sem_post(table->meal_sem);
			return (NULL);
		}	
		sem_post(table->meal_sem);
		usleep(1000);
	}
}

static int	simulation_end(t_table *table)
{
	int			i;
	pthread_t	*waiters;
	pthread_t	monitor;
	
	waiters = malloc(table->n * sizeof(pthread_t));
	if (!waiters)
	{
		free(table->pids);
		sem_unlink("/forks");
		sem_unlink("/write");
		sem_unlink("/meal");
		sem_unlink("/sim");
		return (0);
	}
	i = 0;
	while (i < table->n)
	{
		table->id = i + 1;
		if (pthread_create(&waiters[i], NULL, waiter_thread, table))
		{
			free(table->pids);
			sem_unlink("/forks");
			sem_unlink("/write");
			sem_unlink("/meal");
			sem_unlink("/sim");
			return (0);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_thread, table))
	{
		free(table->pids);
		sem_unlink("/forks");
		sem_unlink("/write");
		sem_unlink("/meal");
		sem_unlink("/sim");
		return (0);
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < table->n)
	{
		pthread_join(waiters[i], NULL);
		i++;
	}
	free(table->pids);
	free(waiters);
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/meal");
	sem_unlink("/sim");
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
	printf("da\n");
	if (!simulation_end(&table))
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		return (EXIT_FAILURE);
	}
	return (0);
}
