/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:39:57 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/06 13:08:23 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philosopher
{
	int				id;
	int				needs_to_eat;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_philosopher;

int					ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(const char *str);

#endif