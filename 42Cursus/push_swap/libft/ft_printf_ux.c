/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:27:54 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/13 12:51:13 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static unsigned int	ft_putnbr(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n / 10)
		count += ft_putnbr(n / 10);
	count++;
	ft_putchar(n % 10 + '0');
	return (count);
}

void	ft_printf_ux(char frmt, unsigned int n, unsigned int *count)
{
	if (frmt == 'u')
		*count += ft_putnbr(n);
	else if (frmt == 'x')
		*count += ft_putnbr_base(n, "0123456789abcdef");
	else
		*count += ft_putnbr_base(n, "0123456789ABCDEF");
}
