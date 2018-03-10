/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:08:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/10 15:08:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void put_pixel_on_img(int x, int y, t_fdf_data *data)
{
	int i;

	if (x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	i = (x * 4) + (y * data->size_line);
	data->img_map[i++] = data->color.blue;
	data->img_map[i++] = data->color.green;
	data->img_map[i] = data->color.red;
}
