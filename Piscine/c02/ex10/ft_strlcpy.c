/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:55 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/10 14:06:57 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "unistd.h"
//#include "string.h"
//#include "stdio.h"
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char	src[5] = "abcde";
	char	dest[3];

	printf("%d", ft_strlcpy(dest, src, 3));
	int i = 0;
	while (dest[i]){
		write(1, &dest[i], 1);
		i++;
	}
	printf("%lu", strlen(dest));
	return (0);
}
*/
