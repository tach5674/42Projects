/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:46:34 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/18 13:02:53 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_sem(t_table *table)
{
	table->forks_sem = sem_open("/forks", O_CREAT | O_EXCL, 0666, table->n);
	table->write_sem = sem_open("/write", O_CREAT | O_EXCL, 0666, 1);
	table->meal_sem = sem_open("/meal", O_CREAT | O_EXCL, 0666, 0);
	table->sim_sem = sem_open("/sim", O_CREAT | O_EXCL, 0666, 1);
	table->kill_sem = sem_open("/kill", O_CREAT | O_EXCL, 0666, 0);
	if (table->forks_sem == SEM_FAILED || table->write_sem == SEM_FAILED
		|| table->meal_sem == SEM_FAILED || table->sim_sem == SEM_FAILED
		|| table->kill_sem == SEM_FAILED)
	{
		write(2, "Error: failed to open semaphore\n",
			ft_strlen("Error: failed to open semaphore\n"));
		exit(1);
	}
	if (sem_unlink("/forks") == -1 || sem_unlink("/write") == -1
		|| sem_unlink("/meal") == -1 || sem_unlink("/sim") == -1
		|| sem_unlink("/kill") == -1)
	{
		write(2, "Error: failed to unlink semaphore\n",
			ft_strlen("Error: failed to unlink semaphore\n"));
		exit(1);
	}
}

void	init_philos(t_table *table)
{
	int	i;

	table->pids = malloc(table->n * sizeof(int));
	if (!table->pids)
		exit_error(table, "allocation failed\n");
	i = 0;
	table->start_time = get_time() + 100;
	table->last_meal_time = table->start_time;
	while (i < table->n)
	{
		table->pids[i] = fork();
		if (table->pids[i] == -1)
		{
			exit_error(table, "fork() call failed\n");
		}
		if (table->pids[i] == 0)
		{
			table->id = i + 1;
			philosopher_process(table);
		}
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	num;

	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\n' || *str == '\r')
		str++;
	num = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			num *= 10;
			num += *str - '0';
			str++;
		}
		else
			return (0);
	}
	return (num);
}

static void	fits_integer(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '0' && ft_strlen(argv[i]) > 1)
			exit_init("Error: an argumnet is not an integer\n");
		if (ft_strlen(argv[i]) > 10 || (ft_strlen(argv[i]) == 10
				&& ft_strcmp(argv[i], "2147483647") > 0))
			exit_init("Error: an argument is not an integer\n");
		i++;
	}
}

void	init(t_table *table, int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		exit_init("Error: wrong number of arguments\n");
	fits_integer(argc, argv);
	table->simulation_over = 0;
	table->has_to_eat = 0;
	table->has_eaten = 0;
	table->n = ft_atoi(argv[1]);
	if (table->n <= 0)
		exit_init("Error: an argument is not a positive integer\n");
	table->time_to_die = ft_atoi(argv[2]) * 1000;
	if (table->time_to_die <= 0)
		exit_init("Error: an argument is not a positive integer\n");
	table->time_to_eat = ft_atoi(argv[3]) * 1000;
	if (table->time_to_eat <= 0)
		exit_init("Error: an argument is not a positive integer\n");
	table->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (table->time_to_sleep <= 0)
		exit_init("Error: an argument is not a positive integer\n");
	if (argc == 6)
	{
		table->has_to_eat = ft_atoi(argv[5]);
		if (table->has_to_eat <= 0)
			exit_init("Error: an argument is not a positive integer\n");
	}
}
