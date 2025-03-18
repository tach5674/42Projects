/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:21:36 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/18 14:38:12 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		return (1 + ft_putnbr_base(-nb, "0123456789"));
	}
	return (ft_putnbr_base(nb, "0123456789"));
}

void	ft_printf_di(int n, unsigned int *count)
{
	*count += ft_putnbr(n);
}
