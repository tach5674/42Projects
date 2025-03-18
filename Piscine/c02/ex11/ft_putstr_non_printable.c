/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:45:54 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/21 09:39:59 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	uc;
	char			*hexdec;

	hexdec = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
			ft_putchar(str[i]);
		else
		{
			uc = (unsigned char)str[i];
			write(1, "\\", 1);
			ft_putchar(hexdec[uc / 16]);
			ft_putchar(hexdec[uc % 16]);
		}
		i++;
	}
}
/*
int main(){
	ft_putstr_non_printable("Cou\xdcoutu vas bien ?");
	return 0;
}
*/
