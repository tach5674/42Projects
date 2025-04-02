/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:02:42 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/02 16:45:44 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	in_base(char *str, char *hexl, char *hexu)
{
	int	i;

	i = 0;
	while (hexl[i])
	{
		if (*str == hexl[i] || *str == hexu[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	convert(char *str, char *hexl, char *hexu)
{
	int	res;
	int	i;

	res = 0;
	while (*str)
	{
		i = in_base(str, hexl, hexu);
		if (i == -1)
			return (-1);
		res *= 16;
		res += i;
		str++;
	}
	return (res);
}

int	atoi_hex(char *str)
{
	char	*hexl;
	char	*hexu;

	hexl = "0123456789abcdef";
	hexu = "0123456789ABCDEF";
	if (!str)
		return (-1);
	if (*str == '0')
	{
		str++;
		if (*str == 'x')
			str++;
		else
			return (-1);
	}
	else
		return (-1);
	return (convert(str, hexl, hexu));
}
