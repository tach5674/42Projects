/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:08:53 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/26 16:27:25 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_write(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		d;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	d = 1;
	while (nb / d >= 10)
	{
		d *= 10;
	}
	while (d >= 1)
	{
		ft_write(nb / d + '0');
		nb = nb % d;
		d /= 10;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		while (*(par->str))
		{
			write(1, par->str, 1);
			(par->str)++;
		}
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		while (*(par->copy))
		{
			write(1, par->copy, 1);
			(par->copy)++;
		}
		write(1, "\n", 1);
		par++;
	}
}
