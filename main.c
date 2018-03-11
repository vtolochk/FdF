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

void multiply_map(t_fdf_data *data, t_fdf_point **map, int value)
{
	int y = 0;
	int x = 0;

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

void draw_line(int x0, int y0, int x1, int y1, t_fdf_data *data)
{

	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;

	while (1)
	{
		put_pixel_on_img(x0, y0, data);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void rotate_x(t_fdf_data *data, t_fdf_point **map)
{
	int y = 0;
	int x = 0;
	double radian;

	radian = data->x_degree * M_PI / 180;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].y = (map[y][x].y * cos(radian)) + (map[y][x].z * sin(radian));
			data->map[y][x].z = -(map[y][x].y * sin(radian)) + (map[y][x].z * cos(radian));
			x++;
		}
		y++;
	}
}

void rotate_y(t_fdf_data *data, t_fdf_point **map)
{
	int y = 0;
	int x = 0;
	double radian;

	radian = data->y_degree * M_PI / 180;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].x = (map[y][x].x * cos(radian)) + (data->map[y][x].z * sin(radian));
			data->map[y][x].z = -(map[y][x].x * sin(radian)) + (data->map[y][x].z * cos(radian));
			x++;
		}
		y++;
	}
}

void rotate_z(t_fdf_data *data, t_fdf_point **map)
{
	int y = 0;
	int x = 0;
	double radian;

	radian = data->z_degree * M_PI / 180;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].x = (data->map[y][x].x * cos(radian)) - (data->map[y][x].y * sin(radian));
			data->map[y][x].y = (map[y][x].x * sin(radian)) + (data->map[y][x].y * cos(radian));
			x++;
		}
		y++;
	}
}

void create_img(t_fdf_data *data)
{
	int bits_pp;
	int size_l;
	int endian;
	void *img_ptr;
	char *img_map;

	int x = 0;
	int y = 0;
	data->color.green = 255;
	data->color.blue = 255;
	data->color.red = 0;
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
				draw_line(data->map[y][x].x + WIN_WIDTH/2, data->map[y][x].y + WIN_HEIGHT/2, data->map[y][x + 1].x  + WIN_WIDTH/2, data->map[y][x + 1].y + WIN_HEIGHT/2, data);
			if (y + 1 < data->max_y)
				draw_line(data->map[y][x].x + WIN_WIDTH/2, data->map[y][x].y + WIN_HEIGHT/2, data->map[y + 1][x].x  + WIN_WIDTH/2, data->map[y + 1][x].y + WIN_HEIGHT/2, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img_ptr);
}

void rotate_map(t_fdf_data *data)
{
	rotate_x(data, data->map_cpy);
	rotate_y(data, data->map_cpy);
	rotate_z(data, data->map_cpy);
	create_img(data);
}

int close_window(int key, t_fdf_data *data)
{
	if (key == 53)
		exit(SUCCESS);
	// X ^
	if (key == 125)
		data->x_degree += 2;
	if (key == 126)
		data->x_degree -= 2;
	// Y > <
	if (key == 124)
		data->y_degree += 2;
	if (key == 123)
		data->y_degree -= 2;
	// Z
	if (key == 6)
		data->z_degree += 2;
	if (key == 7)
		data->z_degree -= 2;
	if (key == 36)
	{
		data->z_degree = 0;
		data->y_degree = 0;
		data->x_degree = 0;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	rotate_map(data);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_fdf_data data;

	init_fdf(&data, argc, argv);
	mlx_hook(data.win_ptr, 2, 5, close_window, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, mouse_close, 0);
	mlx_loop(data.mlx_ptr);
	return (SUCCESS);
}
