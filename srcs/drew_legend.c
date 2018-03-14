/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drew_legend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:04:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/14 15:04:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void drew_start_legend(t_fdf_data *data)
{
	char *str;

	str = "Press space to start";
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIN_WIDTH/2 - ft_strlen(str)*4, WIN_HEIGHT/2 - ft_strlen(str)*4, 0xFFFFFFF, str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 40, 0xFFFFFF, "LEGEND:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 70, 0xFFFFFF, "Up:            'W'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 90, 0xFFFFFF, "Down:          'S'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 110, 0xFFFFFF, "Left:          'A'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 130, 0xFFFFFF, "Right:         'D'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 150, 0xFFFFFF, "Go to start:   'Enter'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 170, 0xFFFFFF, "Rotate:        'Up' 'Down' 'Right' 'Left'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 190, 0xFFFFFF, "Zoom +:        '+'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 210, 0xFFFFFF, "Zoom -:        '-'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 230, 0xFFFFFF, "Colors:        '1 - 6'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 250, 0xFFFFFF, "Increase z:    'Left shift'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 270, 0xFFFFFF, "Decrease z:    'Right shift'");
}

