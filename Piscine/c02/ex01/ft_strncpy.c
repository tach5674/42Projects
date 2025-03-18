/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:04:10 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/10 11:39:18 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "unistd.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[5] = "abcde";
	char	dest[6];

	ft_strncpy(dest, src, 2);
	int i = 0;
	while (dest[i]){
		write(1, &dest[i], 1);
		i++;
	}
	return (0);
}
*/
