/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:53:27 by mzohraby          #+#    #+#             */
/*   Updated: 2025/02/13 12:45:55 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

unsigned int	ft_putnbr_base(unsigned long n, char *base);
void			ft_printf_c(unsigned char c, unsigned int *count);
void			ft_printf_s(char *str, unsigned int *count);
void			ft_printf_p(void *ptr, unsigned int *count);
void			ft_printf_di(int n, unsigned int *count);
void			ft_printf_ux(char frmt, unsigned int n, unsigned int *count);
int				ft_printf(const char *frmt, ...);

#endif
