/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:22:43 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/03 14:17:03 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s(char *str, unsigned int *count)
{
	unsigned int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	*count += i;
}
