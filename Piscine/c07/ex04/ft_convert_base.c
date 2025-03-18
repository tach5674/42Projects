/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:04:11 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/21 09:39:21 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	convert_to_int(char *str, char *base, int len, int sign)
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
		if (j == len)
			return (res * sign);
	}
	return (res * sign);
}

void	convert_to_char(char *res, int nbr, char *base, int *i)
{
	unsigned int	len;
	int				sign;
	unsigned int	n;

	sign = 1;
	if (nbr < 0)
	{
		n = -nbr;
		sign = -1;
	}
	else
		n = nbr;
	len = 0;
	while (base[len])
		len++;
	while (n >= 1)
	{
		res[*i] = base[n % len];
		n /= len;
		(*i)--;
	}
	if (sign < 0)
		res[*i] = '-';
	else
		(*i)++;
}

int	ft_atoi(char *str, char *base_from, int len)
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
	return (convert_to_int(str, base_from, len, sign));
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*res;
	int		len_from;
	int		i;

	res = malloc(33);
	if (!res)
		return (0);
	if (!base_check(base_from) || !base_check(base_to))
		return (0);
	len_from = 0;
	while (base_from[len_from])
		len_from++;
	num = ft_atoi(nbr, base_from, len_from);
	if (num == 0)
	{
		res[0] = base_to[0];
		res[1] = '\0';
		return (res);
	}
	res[32] = '\0';
	i = 31;
	convert_to_char(res, num, base_to, &i);
	return (&res[i]);
}
/*
int	main(void)
{
	printf("%s \n", ft_convert_base("41", "0123456789ABCDEF", "ab"));
	return (0);
}
*/
