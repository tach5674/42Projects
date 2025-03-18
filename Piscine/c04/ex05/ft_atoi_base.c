/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:08:11 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/21 09:25:47 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	convert(char *str, char *base, int len, int sign)
{
	int		res;
	int		j;

	res = 0;
	while (*(str++))
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == *(str - 1))
			{
				res = res * len + j;
				break ;
			}
			j++;
		}
		if (j == len)
			return (res * sign);
	}
	return (res * sign);
}

int	ft_atoi(char *str, char *base, int len)
{
	int		sign;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\n' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (convert(str, base, len, sign));
}

int	base_check(char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	while (*(base + 1))
	{
		if (*base == *(base + 1))
			return (0);
		base++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		len;

	if (!base_check(base))
		return (0);
	len = 0;
	while (base[len])
		len++;
	return (ft_atoi(str, base, len));
}

int	main(void)
{
	printf("%d \n", ft_atoi_base(" 	-80000000", "0123456789ABCDEF"));
	return (0);
}

