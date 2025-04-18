/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:22:30 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/18 16:47:45 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	end_check(t_table *table)
{
	sem_wait(table->sim_sem);
	if (table->simulation_over)
	{
		sem_post(table->sim_sem);
		return (1);
	}
	sem_post(table->sim_sem);
	return (0);
}

void	print_msg(char *msg, t_table *table)
{
	sem_wait(table->write_sem);
	if (end_check(table))
	{
		sem_post(table->write_sem);
		return ;
	}
	printf("%d %d%s", get_time() - table->start_time, table->id, msg);
	sem_post(table->write_sem);
}

void	ft_sleep(int time_to_sleep)
{
	int	current_time;

	current_time = get_time();
	while (get_time() - current_time < time_to_sleep / 1000)
		usleep(100);
}
