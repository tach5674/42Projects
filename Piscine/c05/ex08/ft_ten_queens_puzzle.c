/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:37:05 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/14 10:09:15 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	check(char *str, char c, int i)
{
	int		j;

	j = 1;
	while (--i >= 0)
	{
		if (str[i] == c || str[i] == c + j || str[i] == c - j)
			return (0);
		j++;
	}
	return (1);
}

void	rec(char *str, int *count, int i)
{
	char	c;

	if (i == 10)
	{
		write(1, str, 10);
		write(1, "\n", 1);
		(*count)++;
		return ;
	}
	c = '0';
	while (c <= '9')
	{
		if (check(str, c, i))
		{
			str[i] = c;
			rec(str, count, i + 1);
		}
		c++;
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	char	str[10];
	int		count;

	count = 0;
	rec(str, &count, 0);
	return (count);
}
/*
int main(){
	printf("%d \n", ft_ten_queens_puzzle());
	return 0;
}
*/
