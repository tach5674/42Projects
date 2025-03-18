/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:02:26 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/21 09:37:06 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*hex(unsigned long num, char*hex)
{
	int		i;
	char	*hexdec;

	hexdec = "0123456789abcdef";
	i = 15;
	while (num / 16 >= 1)
	{
		hex[i] = hexdec[num % 16];
		num /= 16;
		i--;
	}
	hex[i] = hexdec[num];
	i--;
	while (i >= 0)
	{
		hex[i] = '0';
		i--;
	}
	return (hex);
}

void	ft_putstr_non_printable(char *str, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (str[i] >= 32 && str[i] < 127)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	ft_hex_str(char *str, unsigned int size)
{
	unsigned int	i;
	unsigned char	uc;
	char			*hexdec;

	hexdec = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		uc = (unsigned char)str[i];
		ft_putchar(hexdec[uc / 16]);
		ft_putchar(hexdec[uc % 16]);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
	while (i < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	s;
	char			adr[16];
	char			*c_addr;

	c_addr = (char *) addr;
	i = 0;
	while (i < size)
	{
		if (size - i < 16)
			s = size - i;
		else
			s = 16;
		hex((unsigned long)(addr + i), adr);
		write(1, adr, 16);
		ft_putchar(' ');
		ft_hex_str(c_addr + i, s);
		ft_putstr_non_printable(c_addr + i, s);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}

int		main(void)
{
	char str[] = "B\0on\0jour les am\0inCoucou\ntu vas biC\xdcoucou\ntu vas  ";
	
	ft_print_memory(str, 60);	
	return (0);
}

