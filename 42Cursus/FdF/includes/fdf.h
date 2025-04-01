/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:46:58 by mzohraby          #+#    #+#             */
/*   Updated: 2025/04/01 19:47:41 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
#include <errno.h>

# define PI 3.14159265358979323846

# define ESC_KEY 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define X 120
# define Y 121
# define Z 122
# define R_LEFT 44
# define R_RIGHT 46

# define Q 113
# define W 119
# define E 101

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define HEIGHT 1080
# define WIDTH 1920

typedef	struct s_point{
	int	x;
	int	y;
	int	z;
	int color;
}	t_point;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**fdf;
	int		**colors;
	char	*input;
	int		height;
	int		width;
	float	offsetX;
	float	offsetY;
	float	targetOffsetX;
	float	targetOffsetY;
	float	scale;
	float	target_scale;
	t_point	a;
	t_point	b;
	int		x1;
	int		y1;
	int		needs_update;
	float	alpha;
	float	betta;
	float	gamma;
	int		x_key;
	int		y_key;
	int		z_key;
	int		projection;
	int		is_rotating;
}	t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_data	data;
}	t_vars;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

void	get_dims(t_data *data);
void	fill_matrix(t_data *data, char *input);

void	free_split(char **nums);
void	free_fdf(int **fdf, int n);
void	free_mlx(t_vars *vars);

void	input_error(char *msg);
void	fill_error(t_data *data, int n, int m);
void	mlx_error(t_vars *vars);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	bresenham(t_vars *vars);

int		atohex(char *str);

int		get_color(t_data *data);

int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		smooth_zoom(t_vars *vars);
int		smooth_translate(t_vars *vars);
int		render_next_frame(t_vars *vars);

void    rotate_x(t_data * data, t_point *a);
void    rotate_y(t_data * data, t_point *a);
void    rotate_z(t_data * data, t_point *a);

int		close_window(t_vars *vars);
void	close_window_escape(t_vars *vars);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	clear(t_vars *vars);

void	isometric(t_point *a);

void	set_point(t_vars *vars, t_point *a, int i, int j);

int		draw(t_vars *vars, int i, int j);

#endif
