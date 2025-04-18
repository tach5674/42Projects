/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:23:29 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/18 13:03:01 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_error(t_table *table, char *msg)
{
	sem_close(table->forks_sem);
	sem_close(table->write_sem);
	sem_close(table->meal_sem);
	sem_close(table->sim_sem);
	sem_close(table->kill_sem);
	free(table->pids);
	write(2, "Error: ", ft_strlen("Error: "));
	write(2, msg, ft_strlen(msg));
	exit(1);
}

static void	exit_init(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (int)1000) + (time.tv_usec / 1000));
}
