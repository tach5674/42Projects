/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:23:29 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/08 15:54:04 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_strlen(const char *s)
{
	int		i;

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

int	ft_atoi(const char *str)
{
	int				num;

	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\n' || *str == '\r')
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

static void	recursive(int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	recursive(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	recursive(n, fd);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (int)1000) + (time.tv_usec / 1000));
}