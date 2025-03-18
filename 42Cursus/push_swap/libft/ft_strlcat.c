/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:03:13 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/21 13:26:58 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
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
