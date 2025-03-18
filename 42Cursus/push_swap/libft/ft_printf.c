/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:33:44 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/13 12:51:05 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printf_body(const char *frmt, va_list args, unsigned int *count)
{
	unsigned int	check;

	check = 0;
	while (*frmt)
	{
		if (*frmt == '%' && !check)
			check = 1;
		else
		{
			if (*frmt == 'c' && check)
				ft_printf_c(va_arg(args, int), count);
			else if (*frmt == 's' && check)
				ft_printf_s(va_arg(args, char *), count);
			else if (*frmt == 'p' && check)
				ft_printf_p(va_arg(args, void *), count);
			else if ((*frmt == 'd' || *frmt == 'i') && check)
				ft_printf_di(va_arg(args, int), count);
			else if ((*frmt == 'u' || *frmt == 'x' || *frmt == 'X') && check)
				ft_printf_ux(*frmt, va_arg(args, unsigned int), count);
			else
				ft_printf_c(*frmt, count);
			check = 0;
		}
		frmt++;
	}
}

int	ft_printf(const char *frmt, ...)
{
	va_list			args;
	unsigned int	count;

	if (!frmt)
		return (0);
	count = 0;
	va_start(args, frmt);
	ft_printf_body(frmt, args, &count);
	va_end(args);
	return (count);
}
