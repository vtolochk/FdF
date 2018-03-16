/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:55:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/16 20:19:12 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_map_down(t_fdf_data *data, double value)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].y = data->map[y][x].y + value;
			data->map_cpy[y][x].y = data->map_cpy[y][x].y + value;
			x++;
		}
		y++;
	}
}

void		move_map_up(t_fdf_data *data, double value)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].y = data->map[y][x].y - value;
			data->map_cpy[y][x].y = data->map_cpy[y][x].y - value;
			x++;
		}
		y++;
	}
}

void		move_map_left(t_fdf_data *data, double value)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].x = data->map[y][x].x - value;
			data->map_cpy[y][x].x = data->map_cpy[y][x].x - value;
			x++;
		}
		y++;
	}
}

void		move_map_right(t_fdf_data *data, double value)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].x = data->map[y][x].x + value;
			data->map_cpy[y][x].x = data->map_cpy[y][x].x + value;
			x++;
		}
		y++;
	}
}
