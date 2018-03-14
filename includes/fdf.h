/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:00:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/13 19:48:14 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>

#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#include "../Libft/includes/libft.h"

# define ERROR 1
# define SUCCESS 0
# define WIN_WIDTH 1300
# define WIN_HEIGHT 900

typedef struct s_fdf_point
{
	double x;
	double y;
	double z;
}              t_fdf_point;

typedef struct s_fdf_center
{
	size_t	x;
	size_t  y;
}               t_fdf_center;

typedef struct s_fdf_color
{
	short blue;
	short green;
	short red;
}               t_fdf_color;

typedef struct  s_fdf_data
{
	void    *mlx_ptr;
	void    *win_ptr;
	char    *img_map;
	int     size_line;
	int     x_degree;
	int     y_degree;
	int     z_degree;
	double     map_size;
	size_t     max_x;
	size_t     max_y;
	t_fdf_center center;
	t_fdf_color color;
	t_fdf_point **map;
	t_fdf_point **map_cpy;
}               t_fdf_data;

void init_fdf(t_fdf_data *data, int argc, char **argv);
void get_coords(t_fdf_data *data, int fd);
void put_pixel_on_img(int x, int y, t_fdf_data *data);
void create_img(t_fdf_data *data, size_t x, size_t y);
void rotate_x(t_fdf_data *data, t_fdf_point **map);
void rotate_y(t_fdf_data *data, t_fdf_point **map);
void rotate_z(t_fdf_data *data, t_fdf_point **map);
void rotate_map(t_fdf_data *data);
void draw_line(int x0, int y0, int x1, int y1, t_fdf_data *data);
void divide_map(t_fdf_data *data, t_fdf_point **map, double value);
void multiply_map(t_fdf_data *data, t_fdf_point **map, double value);
void move_map_down(t_fdf_data *data, double value);
void move_map_up(t_fdf_data *data, double value);
void move_map_left(t_fdf_data *data, double value);
void move_map_right(t_fdf_data *data, double value);
void change_z_height(t_fdf_data *data, double value);
int read_event(int key, t_fdf_data *data);
void drew_start_legend(t_fdf_data *data);

#endif
