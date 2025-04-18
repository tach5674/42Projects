/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:23:29 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/18 16:23:29 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	ft_atoi(const char *str)
{
	int	num;

	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\n' || *str == '\r')
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

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (int)1000) + (time.tv_usec / 1000));
}

int	fits_integer(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '0' && ft_strlen(argv[i]) > 1)
			return (0);
		if (ft_strlen(argv[i]) > 10 || (ft_strlen(argv[i]) == 10
				&& ft_strcmp(argv[i], "2147483647") > 0))
			return (0);
		i++;
	}
	return (1);
}
