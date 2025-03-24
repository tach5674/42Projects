/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:46:58 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/24 17:23:30 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "math.h"
# include "fcntl.h"
# include <stdio.h>

# define ESC_KEY 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**fdf;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	data;
}	t_vars;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		add_shade(int color, double distance);
int		get_opposite(int color);

int		get_height(char *input);
int		get_width(char *input);
void	exit_error(void);
void	free_split(char **nums);
void	free_fdf(int **fdf, int n);
void	free_exit(int **fdf, int i);

#endif
