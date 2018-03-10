/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:00:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/08 16:00:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>

#include <mlx.h>
#include <math.h>
#include <fcntl.h>
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
	size_t     max_x;
	size_t     max_y;
	t_fdf_center center;
	t_fdf_color color;
	t_fdf_point **map;
}               t_fdf_data;

void init_fdf(t_fdf_data *data, int argc, char **argv);
void get_coords(t_fdf_data *data, int fd);
void put_pixel_on_img(int x, int y, t_fdf_data *data);
void multiply_map(t_fdf_data *data, int value);

#endif
