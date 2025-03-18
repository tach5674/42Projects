/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:21:20 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/26 14:48:56 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_op(int a, int b, void (*op)(int, int))
{
	op(a, b);
}

int	main(int argc, char **argv)
{
	void	(*funcs[5])(int, int);

	funcs[0] = &add;
	funcs[1] = &sub;
	funcs[2] = &mul;
	funcs[3] = &div;
	funcs[4] = &mod;
	if (argc != 4)
		return (1);
	if (!ft_strcmp(argv[argc - 2], "+"))
		do_op(ft_atoi(argv[argc - 3]), ft_atoi(argv[argc - 1]), funcs[0]);
	else if (!ft_strcmp(argv[argc - 2], "-"))
		do_op(ft_atoi(argv[argc - 3]), ft_atoi(argv[argc - 1]), funcs[1]);
	else if (!ft_strcmp(argv[argc - 2], "*"))
		do_op(ft_atoi(argv[argc - 3]), ft_atoi(argv[argc - 1]), funcs[2]);
	else if (!ft_strcmp(argv[argc - 2], "/"))
		do_op(ft_atoi(argv[argc - 3]), ft_atoi(argv[argc - 1]), funcs[3]);
	else if (!ft_strcmp(argv[argc - 2], "%"))
		do_op(ft_atoi(argv[argc - 3]), ft_atoi(argv[argc - 1]), funcs[4]);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
