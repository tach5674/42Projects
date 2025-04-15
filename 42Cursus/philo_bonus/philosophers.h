/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayel <mikayel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:39:57 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/15 13:06:44 by mikayel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h> 
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					n;
	int					*pids;
	int					id;
	int					has_to_eat;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	int					last_meal_time;
	int					has_eaten;
	int					start_time;
	int					start_check;
	int					simulation_over;
	sem_t				*forks_sem;
	sem_t				*write_sem;
	sem_t				*sem;
}						t_table;

int						init(t_table *table, int argc, char *argv[]);

void					print_msg(char *msg, t_table *table);
int						end_check(t_philo *philo);

void					philosopher_process(t_table *table);
void					*monitor(void *t);

int						ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_atoi(const char *str);
int						get_time(void);
int						fits_integer(int argc, char *argv[]);

#endif