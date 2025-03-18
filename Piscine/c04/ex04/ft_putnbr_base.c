/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:22:39 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/17 12:41:04 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	str_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*convert(unsigned int nbr, char *base, char *res, unsigned int *id)
{
	unsigned int	b;

	b = (unsigned int)str_len(base);
	res[32] = '\0';
	while (nbr >= 1)
	{
		res[*id] = base[nbr % b];
		nbr /= b;
		(*id)--;
	}
	(*id)++;
	return (res);
}

int	check1(char *b)
{
	int		i;

	i = 0;
	while (b[i])
	{
		if (b[i] == '+' || b[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	check2(char *b)
{
	int		i;
	int		j;

	if (str_len(b) < 2)
		return (0);
	i = 0;
	while (b[i + 1])
	{
		j = i + 1;
		while (b[j])
		{
			if (b[i] == b[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	char			res[33];
	unsigned int	id;

	if (nbr == 0)
	{
		write(1, base, 1);
		return ;
	}
	id = 31;
	if (!check1(base) || !check2(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = (unsigned int)(-nbr);
	}
	else
		n = (unsigned int)nbr;
	convert(n, base, res, &id);
	while (res[id])
	{
		write(1, &res[id], 1);
		id++;
	}
}
/*
int main(void){
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	return 0;
}
*/
