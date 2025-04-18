/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:39:57 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/18 13:01:20 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERROR_EXIT_CODE 1
# define DEAD_EXIT_CODE 2
# define FINISHED_EXIT_CODE 3

typedef struct s_table
{
	int			n;
	int			*pids;
	int			id;
	pthread_t	monitor_thread;
	int			has_to_eat;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_die;
	int			last_meal_time;
	int			has_eaten;
	int			start_time;
	int			start_check;
	int			simulation_over;
	int			exit_code;
	sem_t		*forks_sem;
	sem_t		*write_sem;
	sem_t		*meal_sem;
	sem_t		*sim_sem;
	sem_t		*kill_sem;
}				t_table;

void			init(t_table *table, int argc, char *argv[]);
void			init_philos(t_table *table);
void			init_sem(t_table *table);

void			exit_error(t_table *table, char *msg);

void			print_msg(char *msg, t_table *table);
int				end_check(t_table *table);

void			kill_all(t_table *table);

void			*main_monitor(void *t);

void			philosopher_process(t_table *table);
void			*monitor(void *t);

int				ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
int				get_time(void);

#endif