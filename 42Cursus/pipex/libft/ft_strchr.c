/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:07:36 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/21 18:51:32 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strchr(const char *s, int c)
{
	char	tofind;

	tofind = (char) c;
	while (*s && *s != tofind)
		s++;
	if (*s == tofind)
		return ((char *)s);
	else
		return (NULL);
}
