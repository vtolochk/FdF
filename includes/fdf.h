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
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

typedef struct s_fdf_point
{
	double x;
	double y;
	double z;
}              t_fdf_point;

typedef struct  s_fdf_data
{
	void *mlx_ptr;
	void *win_ptr;
	int     max_x;
	int     max_y;
	t_fdf_point **map;
}               t_fdf_data;

void init_fdf(t_fdf_data *data, int argc, char **argv);
void get_coords(t_fdf_data *data, int fd);

#endif
