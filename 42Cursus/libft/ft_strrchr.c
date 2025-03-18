/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:20:00 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/21 15:26:08 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strrchr(const char *s, int c)
{
	char		tofind;
	const char	*temp;

	temp = NULL;
	tofind = (char) c;
	while (*s)
	{
		if (*s == tofind)
			temp = s;
		s++;
	}
	if (*s == tofind)
		temp = s;
	return ((char *)temp);
}
