/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:32:56 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/11 16:19:26 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"
int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(int argc, char**argv)
{
	printf("%d", ft_strcmp(argv[1], argv[2]));
	return (0);
}
*/
