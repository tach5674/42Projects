/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayel <mikayel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/15 14:14:39 by mikayel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	simulation_start(t_table *table)
{
	int	i;
	
	table->pids = malloc(table->n * sizeof(int));
	if (!table)
		return (0);
	table->forks_sem = sem_open("forks", O_CREAT, 0666, table->n);
	if (!table->sem)
	{
		free(table);
		return (0);	
	}
	table->write_sem = sem_open("write", O_CREAT, 0666, 1);
	if (!table->sem)
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
	return (1);
}

static int	simulation_end(t_table *table)
{
	int	i;

	i = 1;
	waitpid(table->pids[0], NULL, 0);
	while (i < table->n)
	{
		kill(table->pids[i], SIGKILL);
		i++;
	}
	i = 1;
	while (i < table->n)
	{
		waitpid(table->pids[i], NULL, 0);
		i++;
	}
	free(table->pids);
	sem_unlink("forks");
	sem_unlink("write");
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
