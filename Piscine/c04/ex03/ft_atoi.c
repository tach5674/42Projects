/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:27:40 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/26 13:47:47 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"

int	ft_atoi(char *str)
{
	unsigned int	sign;
	int				num;

	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\n' || *str == '\r')
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
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

int main(void){
	printf("%d", ft_atoi("  -+"));
	return 0;
}
