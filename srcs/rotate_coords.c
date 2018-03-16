/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:58:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/16 20:18:31 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_x(t_fdf_data *data, t_fdf_point **map)
{
	size_t x;
	size_t y;
	double radian;

	y = 0;
	radian = data->x_degree * M_PI / 180;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].y = (map[y][x].y * cos(radian)) +  \
			(map[y][x].z * sin(radian));
			data->map[y][x].z = -(map[y][x].y * sin(radian)) + \
			(map[y][x].z * cos(radian));
			x++;
		}
		y++;
	}
}

void		rotate_y(t_fdf_data *data, t_fdf_point **map)
{
	size_t x;
	size_t y;
	double radian;

	y = 0;
	radian = data->y_degree * M_PI / 180;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].x = (map[y][x].x * cos(radian)) + \
			(data->map[y][x].z * sin(radian));
			data->map[y][x].z = -(map[y][x].x * sin(radian)) + \
			(data->map[y][x].z * cos(radian));
			x++;
		}
		y++;
	}
}

void		rotate_z(t_fdf_data *data, t_fdf_point **map)
{
	size_t x;
	size_t y;
	double radian;

	y = 0;
	radian = data->z_degree * M_PI / 180;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].x = (data->map[y][x].x * cos(radian)) - \
			(data->map[y][x].y * sin(radian));
			data->map[y][x].y = (map[y][x].x * sin(radian)) + \
			(data->map[y][x].y * cos(radian));
			x++;
		}
		y++;
	}
}

void		change_z_height(t_fdf_data *data, double value)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].z = data->map[y][x].z * value;
			data->map_cpy[y][x].z = data->map_cpy[y][x].z * value;
			x++;
		}
		y++;
	}
}

void		rotate_map(t_fdf_data *data)
{
	rotate_x(data, data->map_cpy);
	rotate_y(data, data->map_cpy);
	rotate_z(data, data->map_cpy);
	create_img(data, 0, 0);
}
