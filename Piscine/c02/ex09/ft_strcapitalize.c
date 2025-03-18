/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:32:54 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/09 16:51:49 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"

void	ft_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		check;

	ft_lowercase(str);
	i = 0;
	check = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (check == 1)
			{
				str[i] -= 32;
				check = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
			check = 0;
		else
			check = 1;
		i++;
	}
	return (str);
}
/*
int main(int argc, char** argz){
	char* str = ft_strcapitalize(argz[1]);
	int i = 0;
	while(str[i]){
		printf("%c", str[i]);
		i++;
	}
	return 0;
}
*/
