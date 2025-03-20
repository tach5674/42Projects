/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:21 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/21 18:36:14 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	if (start >= ft_strlen(s))
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	else if (ft_strlen(s) - start < len)
		res = malloc(ft_strlen(s) - start + 1);
	else
		res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
