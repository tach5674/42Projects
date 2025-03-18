/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:55:30 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/26 14:34:03 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "unistd.h"

void	ft_putchar(char c);
void	recursive(int nb);
void	ft_putnbr(int nb);
void	add(int a, int b);
void	sub(int a, int b);
void	mul(int a, int b);
void	div(int a, int b);
void	mod(int a, int b);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
void	do_op(int a, int b, void (*op)(int, int));

#endif
