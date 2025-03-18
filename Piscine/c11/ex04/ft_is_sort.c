/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:10:18 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/26 17:06:44 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int	str_cmp(int a, int b)
{
	return (a - b);
}
*/
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	c1;
	int	c2;

	c1 = 1;
	c2 = 1;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			c1 = 0;
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			c2 = 0;
		i++;
	}
	if (c1 || c2)
		return (1);
	else
		return (0);
}
/*
int main(int argc, char **argv)
{
	int		i;
	int		str[] = {};

	printf("%d \n", ft_is_sort(str, 0, &str_cmp));
	return (0);
}
*/
