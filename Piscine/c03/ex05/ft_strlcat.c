/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:03:13 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/12 12:10:43 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "unistd.h"
//#include "stdio.h"
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_size;
	unsigned int	src_size;

	dest_size = str_len(dest);
	src_size = str_len(src);
	if (dest_size >= size)
		return (size + src_size);
	i = 0;
	while (src[i] && i < size - dest_size - 1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
/*
int	main(void)
{
	char src[] = "8901";
	char dest[12] = "01234567";
	int i = 0;
	printf("%d \n", ft_strlcat(dest, src, 3));
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return (0);
}
*/
