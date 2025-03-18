/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:21:36 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/13 12:51:22 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_putnbr_helper(int nb, unsigned int *count)
{
	int		d;
	char	c;

	d = 1;
	while (nb / d >= 10)
		d *= 10;
	while (d >= 1)
	{
		c = nb / d + '0';
		write(1, &c, 1);
		nb = nb % d;
		d /= 10;
		(*count)++;
	}
	return (*count);
}

static unsigned int	ft_putnbr(int nb)
{
	unsigned int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count++;
	}
	return (ft_putnbr_helper(nb, &count));
}

void	ft_printf_di(int n, unsigned int *count)
{
	*count += ft_putnbr(n);
}
