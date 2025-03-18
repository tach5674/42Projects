/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:34:26 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/21 15:32:56 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	if ((dst == NULL && src == NULL) || n == 0)
		return (dst);
	cdst = (unsigned char *) dst;
	csrc = (unsigned char *) src;
	while (n--)
		*cdst++ = *csrc++;
	return (dst);
}
