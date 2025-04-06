/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:23:29 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/06 12:45:06 by mzohraby         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	unsigned int	sign;
	int				num;

	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\n' || *str == '\r')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num * sign);
}
