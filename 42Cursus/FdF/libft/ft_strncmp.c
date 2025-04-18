/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:34:28 by mzohraby          #+#    #+#             */
/*   Updated: 2025/01/21 16:19:20 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
/*
int	main(int argc, char**argv)
{
	printf("%d", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	return (0);
}
*/
