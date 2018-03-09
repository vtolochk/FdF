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
		mlx_string_put(data->mlx_ptr, data->win_ptr, 300, 300, 0xFFFFFF, "hello world");
		img_ptr = mlx_new_image(data->mlx_ptr, 100, 100);
		points = (int *)mlx_get_data_addr(img_ptr, &bits_pp, &size_l, &endian);
		for(int i = 0; i < size_l * 10; i++)
			points[i] = 9999;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, 100, 100);
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
