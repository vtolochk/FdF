/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:34:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/09 13:34:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int validate_fdf(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		write(2, "Usage: ./fdf <filename>\n", 25);
		exit(ERROR);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_printf("Not a valid file %s\n", argv[1]);
		exit(ERROR);
	}
	return (fd);
}

static void get_center(t_fdf_data *data)
{
	if (data->max_x > 90 || data->max_y > 90)
	{
		multiply_map(data, data->map, 5);
		multiply_map(data, data->map_cpy, 5);
		data->map_size = 5;
		data->center.x = (WIN_WIDTH/2 - (data->max_x * 5)/2);
		data->center.y = (WIN_HEIGHT/2 - (data->max_y * 5)/2);
	}
	else
	{
		multiply_map(data, data->map, 30);
		multiply_map(data, data->map_cpy, 30);
		data->map_size = 30;
		data->center.x = (WIN_WIDTH/2 - (data->max_x * 30)/2);
		data->center.y = (WIN_HEIGHT/2 - (data->max_y * 30)/2);
	}
}

void    init_fdf(t_fdf_data *data, int argc, char **argv)
{
	int     fd;
	void    *mlx_ptr;
	void    *win_ptr;
	char    *window_name;

	fd = validate_fdf(argc, argv);
	get_coords(data, fd);
	window_name = ft_strjoin("FdF - ", argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, window_name);
	if (!mlx_ptr || !win_ptr)
	{
		ft_strdel(&window_name);
		exit (ERROR);
	}
	data->mlx_ptr = mlx_ptr;
	data->win_ptr = win_ptr;
	data->z_height = 0;
	data->map_size = 0;
	data->x_degree = 0;
	data->y_degree = 0;
	data->z_degree = 0;
	get_center(data);
	ft_strdel(&window_name);
}
