/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:11:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/14 14:11:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void color_helper(int key, t_fdf_data *data)
{
	if (key == 18)
	{
		data->color.blue = 0;
		data->color.red = 0;
		data->color.green = 255;
	}
	if (key == 19)
	{
		data->color.blue = 0;
		data->color.red = 255;
		data->color.green = 0;
	}
	if (key == 20)
	{
		data->color.blue = 255;
		data->color.red = 0;
		data->color.green = 0;
	}
	if (key == 21)
	{
		data->color.blue = 0;
		data->color.red = 255;
		data->color.green = 255;
	}
}

static void change_color(int key, t_fdf_data *data)
{
	if (key == 18 || key == 19 || key == 20 || key == 21)
		color_helper(key, data);
	if (key == 23)
	{
		data->color.blue = 255;
		data->color.red = 0;
		data->color.green = 255;
	}
	if (key == 22)
	{
		data->color.blue = 255;
		data->color.red = 255;
		data->color.green = 255;
	}
}

static void clear_and_zoom(int key, t_fdf_data *data)
{
	if (key == 36)
	{
		data->z_degree = 0;
		data->y_degree = 0;
		data->x_degree = 0;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	if (key == 27)
	{
		divide_map(data, data->map, data->map_size);
		divide_map(data, data->map_cpy, data->map_size);
		multiply_map(data, data->map, data->map_size - 0.9);
		multiply_map(data, data->map_cpy, data->map_size - 0.9);
	}
	if (key == 24)
	{
		divide_map(data, data->map, data->map_size);
		divide_map(data, data->map_cpy, data->map_size);
		multiply_map(data, data->map, data->map_size + 0.9);
		multiply_map(data, data->map_cpy, data->map_size + 0.9);
	}
}

static void change_degree(int key, t_fdf_data *data)
{
	if (key == 125)
		data->x_degree += 2;
	if (key == 126)
		data->x_degree -= 2;
	if (key == 124)
		data->y_degree += 2;
	if (key == 123)
		data->y_degree -= 2;
	if (key == 6)
		data->z_degree += 2;
	if (key == 7)
		data->z_degree -= 2;
}

int read_event(int key, t_fdf_data *data)
{
	if (key == 53)
		exit(SUCCESS);
	if (key == 125 || key == 126 || key == 124 ||
	    key == 123 || key == 6 || key == 7)
		change_degree(key, data);
	if (key == 36 || key == 27 || key == 24)
		clear_and_zoom(key, data);
	if (key == 257)
		change_z_height(data, 1.8);
	if (key == 258)
		change_z_height(data, 0.5);
	if (key == 18 || key == 19 || key == 20 || key == 21 || key == 22 || key == 23)
		change_color(key, data);
	if (key == 2)
		move_map_right(data, 5);
	if (key == 0)
		move_map_left(data, 5);
	if (key == 13)
		move_map_up(data, 5);
	if (key == 1)
		move_map_down(data, 5);
	rotate_map(data);
	return (SUCCESS);
}