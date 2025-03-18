/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:27:54 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/18 14:47:01 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_ux(char frmt, unsigned int n, unsigned int *count)
{
	if (frmt == 'u')
		*count += ft_putnbr_base(n, "0123456789");
	else if (frmt == 'x')
		*count += ft_putnbr_base(n, "0123456789abcdef");
	else
		*count += ft_putnbr_base(n, "0123456789ABCDEF");
}
