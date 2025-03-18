/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:20:43 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/08 12:04:18 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		check;

	check = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'z' || (str[i] > 'Z' && str[i] < 'a'))
			check = 0;
		i++;
	}
	return (check);
}
/*
int main(int argc, char** argz){
	printf("%d", ft_str_is_alpha(argz[1]));
	return 0;
}
*/
