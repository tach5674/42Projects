/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:48:30 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/23 16:57:15 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*positive(char *res, int n, unsigned int sign)
{
	unsigned int	d;
	unsigned int	count;

	count = 1;
	d = 1;
	while (n / d > 9)
	{
		d *= 10;
		count++;
	}
	res = malloc(count + 1 + sign);
	if (!res)
		return (NULL);
	res[count + sign] = '\0';
	while (count--)
	{
		res[count + sign] = '0' + n % 10;
		n /= 10;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	sign;

	res = NULL;
	if (n == -2147483648)
	{
		res = ft_strdup("-2147483648");
		if (!res)
			return (NULL);
		return (res);
	}
	else if (n == 0)
	{
		res = ft_strdup("0");
		if (!res)
			return (NULL);
		return (res);
	}
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	return (positive(res, n, sign));
}
