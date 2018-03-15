/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drew_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:57:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/14 13:57:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void move_to_center(t_fdf_point *first_point, t_fdf_point *second_point)
{
	first_point->x = first_point->x + WIN_WIDTH/2;
	first_point->y = first_point->y + WIN_HEIGHT/2;
	second_point->x = second_point->x + WIN_WIDTH/2;
	second_point->y = second_point->y + WIN_HEIGHT/2;
}

static void get_length(t_fdf_coords *length, t_fdf_point first, t_fdf_point second)
{
	length->y = abs((int)second.y - (int)first.y);
	length->x = abs((int)second.x - (int)first.x);
}

static void get_error(t_fdf_coords length, int *error)
{
	if (length.x > length.y)
		*error = length.x/2;
	else
		*error = -length.y/2;
}

static void get_increment(t_fdf_point first, t_fdf_point second, t_fdf_coords *increment)
{
	if ((int)first.x < (int)second.x)
		increment->x = 1;
	else
		increment->x = -1;
	if ((int)first.y < (int)second.y)
		increment->y = 1;
	else
		increment->y = -1;
}

void draw_line(t_fdf_point first_point, t_fdf_point second_point, t_fdf_data *data, int error)
{
	int save_error;
	t_fdf_coords increment;
	t_fdf_coords length;

	move_to_center(&first_point, &second_point);
	get_length(&length, first_point, second_point);
	get_error(length, &error);
	get_increment(first_point, second_point, &increment);
	while (1)
	{
		put_pixel_on_img((int)first_point.x, (int)first_point.y, data);
		if ((int)first_point.x == (int)second_point.x && (int)first_point.y == (int)second_point.y)
			break;
		save_error = error;
		if (save_error > -length.x)
		{
			error = error - length.y;
			first_point.x = (int)first_point.x + increment.x;
		}
		if (save_error < length.y)
		{
			error = error + length.x;
			first_point.y = (int)first_point.y + increment.y;
		}
	}
}