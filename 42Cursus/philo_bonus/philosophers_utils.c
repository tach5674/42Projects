/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayel <mikayel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:22:30 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/17 17:05:30 by mikayel          ###   ########.fr       */
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
	printf("%d %d %s", get_time() - table->start_time, table->id, msg);
	sem_post(table->write_sem);
}
