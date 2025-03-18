/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:30:28 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/21 16:15:31 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tofind;
	unsigned char	*cs;

	cs = (unsigned char *) s;
	tofind = (unsigned char) c;
	while (n && *cs != tofind)
	{
		n--;
		cs++;
	}
	if (n == 0)
		return (NULL);
	else
		return ((void *)cs);
}
