/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:42:48 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/26 16:27:08 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par);

int	str_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_copy(char *str)
{
	char	*res;
	int		i;

	res = malloc(str_len(str) + 1);
	if (!res)
		return (0);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					i;

	res = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < ac)
	{
		res[i].size = str_len(av[i]);
		res[i].str = av[i];
		res[i].copy = str_copy(av[i]);
		if (!(res[i].copy))
			return (0);
		i++;
	}
	res[i].size = 0;
	res[i].str = 0;
	res[i].copy = 0;
	return (res);
}
/*	
int	main(void)
{
	char	*str[3] = {"dassd", "", "das"};
	struct s_stock_str	*res = ft_strs_to_tab(3, str);
	res[0].copy[0] = 'a';
	ft_show_tab(res);
	return (0)
}
*/
