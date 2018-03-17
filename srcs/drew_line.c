/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drew_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:57:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/17 13:58:39 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_to_center(t_fdf_point *first_point, t_fdf_point *second_point)
{
	first_point->x = first_point->x + WIN_WIDTH / 2;
	first_point->y = first_point->y + WIN_HEIGHT / 2;
	second_point->x = second_point->x + WIN_WIDTH / 2;
	second_point->y = second_point->y + WIN_HEIGHT / 2;
}

static void	get_length(t_fdf_coords *length, t_fdf_point first, t_fdf_point sec)
{
	length->y = abs((int)sec.y - (int)first.y);
	length->x = abs((int)sec.x - (int)first.x);
}

static void	get_error(t_fdf_coords length, int *error)
{
	if (length.x > length.y)
		*error = length.x / 2;
	else
		*error = -length.y / 2;
}

static void	get_increment(t_fdf_point frs, t_fdf_point sec, t_fdf_coords *incr)
{
	if ((int)frs.x < (int)sec.x)
		incr->x = 1;
	else
		incr->x = -1;
	if ((int)frs.y < (int)sec.y)
		incr->y = 1;
	else
		incr->y = -1;
}

void		draw_line(t_fdf_point frs_pt, t_fdf_point sec_pt, \
	t_fdf_data *d, int error)
{
	int				save_error;
	t_fdf_coords	increment;
	t_fdf_coords	length;

	move_to_center(&frs_pt, &sec_pt);
	get_length(&length, frs_pt, sec_pt);
	get_error(length, &error);
	get_increment(frs_pt, sec_pt, &increment);
	while (1)
	{
		put_pixel_on_img((int)frs_pt.x, (int)frs_pt.y, d);
		if ((int)frs_pt.x == (int)sec_pt.x && (int)frs_pt.y == (int)sec_pt.y)
			break ;
		save_error = error;
		if (save_error > -length.x)
		{
			error = error - length.y;
			frs_pt.x = (int)frs_pt.x + increment.x;
		}
		if (save_error < length.y)
		{
			error = error + length.x;
			frs_pt.y = (int)frs_pt.y + increment.y;
		}
	}
}
