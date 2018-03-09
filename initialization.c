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

static void get_coords(t_fdf_data *data, int fd)
{
	int y;
	int x;
	char *line;
	char **ptr;

	y = 0;
	x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		ptr = ft_strsplit(line, ' ');
		while (ptr++)
			x++;
		free(line); // need to figure out how to use it before free
		ft_free_tab((void **)ptr);
	}
	data->map = (t_fdf_point **)malloc(sizeof(t_fdf_point *) * (y + 1));
	data->map[y + 1] = NULL;
	y = 0;
	while (data->map[y])
	{
		data->map[y] = (t_fdf_point *)malloc(sizeof(t_fdf_point) * (x + 1));
		y++;
	}
}

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
	ft_strdel(&window_name);
}
