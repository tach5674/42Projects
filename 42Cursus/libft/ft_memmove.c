/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:18:04 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/23 16:06:05 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	if ((dst == NULL && src == NULL) || len == 0)
		return (dst);
	cdst = (unsigned char *) dst;
	csrc = (unsigned char *) src;
	if (cdst <= csrc)
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	else
	{
		while (len--)
			*(cdst + len) = *(csrc + len);
	}
	return (dst);
}
