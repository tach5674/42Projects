/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:57:12 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/03 19:12:23 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned int	count;

	count = 0;
	if (n / ft_strlen(base))
		count += ft_putnbr_base(n / ft_strlen(base), base);
	count++;
	write(1, &base[n % ft_strlen(base)], 1);
	return (count);
}
