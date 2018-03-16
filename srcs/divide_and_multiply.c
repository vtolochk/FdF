/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_multiply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:56:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/16 20:29:37 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	divide_map(t_fdf_data *data, t_fdf_point **map, double value)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			map[y][x].y = map[y][x].y / value;
			map[y][x].x = map[y][x].x / value;
			x++;
		}
		y++;
	}
}

void	multiply_map(t_fdf_data *data, t_fdf_point **map, double value)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			map[y][x].y = map[y][x].y * value;
			map[y][x].x = map[y][x].x * value;
			x++;
		}
		y++;
	}
}
