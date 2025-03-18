/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:06:57 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/03 15:12:31 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(void *ptr, unsigned int *count)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	*count += ft_putnbr_base(addr, "0123456789abcdef") + 2;
}
