/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:18:39 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/10 13:17:32 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"

int	ft_str_is_uppercase(char *str)
{
	int		i;
	int		check;

	check = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
			check = 0;
		i++;
	}
	return (check);
}
/*
int main(int argc, char** argz){
	printf("%d", ft_str_is_upeercase(argz[1]));
	return 0;
}
*/
