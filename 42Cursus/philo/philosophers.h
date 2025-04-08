/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:39:57 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/08 17:56:02 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					n;
	int					has_to_eat;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	int					start_time;
	int					simulation_over;
	pthread_t			death_monitor;
	pthread_mutex_t		simulation_mutex;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}						t_table;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					has_eaten;
	int					last_meal_time;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	t_table				*table;
}						t_philo;

int						ft_strlen(const char *s);
void					ft_putstr_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_atoi(const char *str);
int						get_time(void);

void					destroy_mutexes(t_table *table, int n);

int						fits_integer(int argc, char *argv[]);
int						mutex_init(t_table *table);
void					philos_init(t_table *table);
int						fill_table(t_table *table, int argc, char *argv[]);
int						init(t_table *table, int argc, char *argv[]);

#endif