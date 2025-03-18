/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:14:27 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/12 12:09:08 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"
char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[j + i] == to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char src[] = "fra";
	char dest[] = "fafrafa";
	int i = 0;
	char *res = ft_strstr(dest, src);
	printf("%s", res);
	return (0);
}
*/
