/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:58:31 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/08 15:58:47 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int mouse_close(void)
{
	exit(SUCCESS);
}

int close_window(int key, t_fdf_data *data)
{
	int bits_pp;
	int size_l;
	int endian;
	void *img_ptr;
	int *points;

	if (key == 53)
		exit(SUCCESS);
	if (key == 49)
	{
		int i = 0;
		int j = 0;
		while (i < data->max_y)
		{
			j = 0;
			while (++j < data->max_x)
			{
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->map[i][j].x + WIN_WIDTH/2, data->map[i][j].y + WIN_HEIGHT/2, 0xFFFFFF);
			}
			i++;
		}
	}
	if (key == 82)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	t_fdf_data data;

	init_fdf(&data, argc, argv);
	mlx_hook(data.win_ptr, 2, 5, close_window, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, mouse_close, 0);
	mlx_loop(data.mlx_ptr);
	return (SUCCESS);
}
