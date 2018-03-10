/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:45:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/09 16:45:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static char *get_line_and_size(int fd, size_t *x, size_t *y)
{
	char    *line;
	char    *temp;
	char   *big_line;
	char    **ptr;

	big_line = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		(*y)++;
		ptr = ft_strsplit(line, ' ');
		while (ptr[(*x)])
			(*x)++;
		temp = big_line;
		big_line = ft_strjoin(big_line, "\n");
		free(temp);
		temp = big_line;
		big_line = ft_strjoin(big_line, line);
		free(temp);
		free(line);
		ft_free_tab((void **)ptr);
	}
	close(fd);
	temp = big_line;
	big_line = ft_strtrim(big_line);
	ft_strdel(&temp);
	return (big_line);
}

static void get_z_coord(t_fdf_data *data, char *line)
{
	int i;
	int j;
	char **lines;
	char **numbers;

	i = 0;
	lines = ft_strsplit(line, '\n');
	while (i < data->max_y)
	{
		j = 0;
		numbers = ft_strsplit(lines[i], ' ');
		while (j < data->max_x)
		{
			data->map[i][j].y = (double)i;
			data->map[i][j].x = (double)j;
			data->map[i][j].z = (double)ft_atoi(numbers[j]);
			j++;
		}
		i++;
	}
	ft_free_tab((void**)lines);
	ft_free_tab((void **)numbers);
}

void get_coords(t_fdf_data *data, int fd)
{
	size_t y;
	size_t x;
	char   *big_line;

	y = 0;
	x = 0;
	big_line = get_line_and_size(fd, &x, &y);
	data->max_y = y;
	data->max_x = x;
	data->map = (t_fdf_point **)malloc(sizeof(t_fdf_point *) * (y + 1));
	data->map[y + 1] = NULL;
	y = 0;
	while (data->map[y])
		data->map[y++] = (t_fdf_point *)malloc(sizeof(t_fdf_point) * (x));
	get_z_coord(data, big_line);
	ft_strdel(&big_line);
}