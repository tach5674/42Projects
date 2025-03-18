/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:00:44 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/10 17:58:18 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "unistd.h"

unsigned int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	dest_size;

	dest_size = str_len(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char src[] = "8901";
	char dest[12] = "1234567";
	int i = 0;
	ft_strcat(dest, src);
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return (0);
}
*/
