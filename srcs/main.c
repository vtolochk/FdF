/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:58:31 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/13 19:35:43 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int mouse_close(void)
{
	exit(SUCCESS);
}

void create_img(t_fdf_data *data, size_t x, size_t y)
{
	int bits_pp;
	int size_l;
	int endian;
	void *img_ptr;
	char *img_map;

	img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img_map = mlx_get_data_addr(img_ptr, &bits_pp, &size_l, &endian);
	data->size_line = size_l;
	data->img_map = img_map;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			if (x + 1 < data->max_x)
				draw_line(data->map[y][x], data->map[y][x + 1], data, 0);
			if (y + 1 < data->max_y)
				draw_line(data->map[y][x], data->map[y + 1][x], data, 0);
			x++;
		}
		y++;
	}
	if (data->max_y == 1 && data->max_x == 1)
		put_pixel_on_img(data->map[y][x].x + WIN_WIDTH/2, data->map[y][x].y + WIN_WIDTH/2, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img_ptr);
}

int main(int argc, char **argv)
{
	t_fdf_data data;

	init_fdf(&data, argc, argv);
	mlx_hook(data.win_ptr, 2, 5, read_event, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, mouse_close, 0);
	drew_start_legend(&data);
	mlx_loop(data.mlx_ptr);
	return (SUCCESS);
}
