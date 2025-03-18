/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:03:26 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/10 18:11:16 by mzohraby         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_size;

	dest_size = str_len(dest);
	i = 0;
	while (src[i] && i < nb)
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
	ft_strncat(dest, src, 10);
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return (0);
}
*/
