/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:22:30 by mikayel           #+#    #+#             */
/*   Updated: 2025/04/16 13:34:55 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	end_check(t_table *table)
{
	sem_wait(table->sim_sem);
	if (table->exit_code)
	{
		sem_post(table->sim_sem);
		return (table->exit_code);
	}
	sem_post(table->sim_sem);
	return (0);
}

void	print_msg(char *msg, t_table *table)
{
	if (end_check(table))
		return ;
	sem_wait(table->write_sem);
	printf("%d %d %s", get_time() - table->start_time, table->id, msg);
	sem_post(table->write_sem);
}
