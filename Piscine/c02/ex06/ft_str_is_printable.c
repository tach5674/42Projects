/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:23:14 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/08 12:31:26 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"

int	ft_str_is_printable(char *str)
{
	int		i;
	int		check;

	check = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			check = 0;
		i++;
	}
	return (check);
}
/*
int main(int argc, char** argz){
	printf("%d", ft_str_is_printable(argz[1]));
	return 0;
}
*/
