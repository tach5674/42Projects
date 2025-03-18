/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:53:17 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/09 17:43:50 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "unistd.h"

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	src[5] = "abcde";
	char	dest[6];

	ft_strcpy(dest, src);
	int i = 0;
	while (dest[i]){
		write(1, &dest[i], 1);
		i++;
	}	
	return (0);
}
*/
