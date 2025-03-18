/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:12:34 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/08 12:14:42 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"

int	ft_str_is_lowercase(char *str)
{
	int		i;
	int		check;

	check = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
			check = 0;
		i++;
	}
	return (check);
}
/*
int main(int argc, char** argz){
	printf("%d", ft_str_is_lowercase(argz[1]));
	return 0;
}
*/
