/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/06 13:49:54 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	validation(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		return (1);
	}
	while (argc--)
	{
		if (ft_atoi(argv[argc]) < 0)
		{
			ft_putstr_fd("Invalid arguments\n", 2);
			return (1);
		}
	}
	return (0);
}

void	*philosopher_thread(void *self)
{
	return (self);
}

int	init(int n, t_philosopher *philosophers, pthread_mutex_t *forks, pthread_t *threads)
{
	int	i;

	philosophers = malloc(n * sizeof(t_philosopher));
	if (!philosophers)
		return (0);
	forks = malloc(n * sizeof(pthread_mutex_t));
	if (!forks)
	{
		free(philosophers);
		return (0);
	}
	threads = malloc(n * sizeof(pthread_t));
	if (!threads)
	{
		free(philosophers);
		free(forks);
		return (0);
	}
	i = -1;
	return (0);
}

void	setup(int argc, char *argv[], t_philosopher *philosophers, pthread_mutex_t *forks)
{
	int	i;
	int	n;
	
	n = ft_atoi(argv[1]);
	i = -1;
	while (++i < n)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < n)
	{
		philosophers[i].id = i;
		if (argc == 6)
			philosophers[i].needs_to_eat = ft_atoi(argv[5]);
		else
			philosophers[i].needs_to_eat = -1;
		philosophers[i].left = &forks[i % n];
		philosophers[i].left = &forks[(i + 1) % n];
		philosophers[i].time_to_eat = ft_atoi(argv[3]);
		philosophers[i].time_to_sleep = ft_atoi(argv[4]);
	}
}

int	main(int argc, char *argv[])
{
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	int				i;
	int				n;
	
	if (validation(argc, argv))
		return (0);
	n = ft_atoi(argv[1]);
	if (n == 0)
		return (0);
	init(argv[1], philosophers, forks, threads);
	i = -1;
	while (++i < n)
	{
		if (pthread_create(&threads[i], NULL, philosopher_thread, &philosophers[i]) != 0)
		{
			return exit_error();
		}
		
	}
	join_threads(threads, n);
	return (0);
}
