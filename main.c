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

void multiply_map(t_fdf_data *data, int value)
{
	int y = 0;
	int x = 0;

	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].y = data->map[y][x].y * value;
			data->map[y][x].x = data->map[y][x].x * value;
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
		if (x0==x1 && y0==y1)
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

void rotate_x(t_fdf_data *data)
{
	int y = 0;
	int x = 0;

	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].y = (data->map[y][x].y * cos(6)) + (data->map[y][x].z * sin(6));
			x++;
		}
		y++;
	}
}

void rotate_y(t_fdf_data *data)
{
	int y = 0;
	int x = 0;

	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].x = (data->map[y][x].x * cos(6)) + (data->map[y][x].z * sin(6));
			x++;
		}
		y++;
	}
}

void rotate_z(t_fdf_data *data)
{
	int y = 0;
	int x = 0;

	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			data->map[y][x].x = (data->map[y][x].x * cos(6)) - (data->map[y][x].y * sin(6));
			data->map[y][x].y = (data->map[y][x].x * sin(6)) + (data->map[y][x].y * cos(6));
			x++;
		}
		y++;
	}
}



int close_window(int key, t_fdf_data *data)
{
	int bits_pp;
	int size_l;
	int endian;
	void *img_ptr;
	char *img_map;

	int x = 0;
	int y = 0;
	if (key == 53)
		exit(SUCCESS);
	if (key == 49)
	{
		img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		img_map = mlx_get_data_addr(img_ptr, &bits_pp, &size_l, &endian);
		data->size_line = size_l;
		data->img_map = img_map;
		while (y < data->max_y)
		{
			x = 0;
			while (x < data->max_x)
			{
				data->color.green = 255;
				data->color.blue = 255;
				data->color.red = 0;
				if (x + 1 < data->max_x)
					draw_line(data->map[y][x].x, data->map[y][x].y, data->map[y][x + 1].x, data->map[y][x + 1].y, data);
				if (y + 1 < data->max_y)
					draw_line(data->map[y][x].x, data->map[y][x].y, data->map[y + 1][x].x, data->map[y + 1][x].y, data);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, data->center.x, data->center.y);
	}
	if (key == 123)
	{
		img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		img_map = mlx_get_data_addr(img_ptr, &bits_pp, &size_l, &endian);
		data->size_line = size_l;
		data->img_map = img_map;
		rotate_x(data);
		while (y < data->max_y)
		{
			x = 0;
			while (x < data->max_x)
			{
				data->color.green = 255;
				data->color.blue = 255;
				data->color.red = 0;
				if (x + 1 < data->max_x)
					draw_line(data->map[y][x].x, data->map[y][x].y, data->map[y][x + 1].x, data->map[y][x + 1].y, data);
				if (y + 1 < data->max_y)
					draw_line(data->map[y][x].x, data->map[y][x].y, data->map[y + 1][x].x, data->map[y + 1][x].y, data);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, data->center.x, data->center.y);
		mlx_destroy_image(data->mlx_ptr, img_ptr);
	}
	if (key == 124)
	{
		img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		img_map = mlx_get_data_addr(img_ptr, &bits_pp, &size_l, &endian);
		data->size_line = size_l;
		data->img_map = img_map;
		rotate_y(data);
		while (y < data->max_y)
		{
			x = 0;
			while (x < data->max_x)
			{
				data->color.green = 255;
				data->color.blue = 255;
				data->color.red = 0;
				if (x + 1 < data->max_x)
					draw_line(data->map[y][x].x, data->map[y][x].y, data->map[y][x + 1].x, data->map[y][x + 1].y, data);
				if (y + 1 < data->max_y)
					draw_line(data->map[y][x].x, data->map[y][x].y, data->map[y + 1][x].x, data->map[y + 1][x].y, data);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, data->center.x, data->center.y);
		mlx_destroy_image(data->mlx_ptr, img_ptr);
	}
	if (key == 125)
	{
		img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		img_map = mlx_get_data_addr(img_ptr, &bits_pp, &size_l, &endian);
		data->size_line = size_l;
		data->img_map = img_map;
		rotate_z(data);
		while (y < data->max_y)
		{
			x = 0;
			while (x < data->max_x)
			{
				data->color.green = 255;
				data->color.blue = 255;
				data->color.red = 0;
				if (x + 1 < data->max_x)
					draw_line(data->map[y][x].x, data->map[y][x].y, data->map[y][x + 1].x, data->map[y][x + 1].y, data);
				if (y + 1 < data->max_y)
					draw_line(data->map[y][x].x, data->map[y][x].y, data->map[y + 1][x].x, data->map[y + 1][x].y, data);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, data->center.x, data->center.y);
		mlx_destroy_image(data->mlx_ptr, img_ptr);
	}
	if (key == 36)
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
