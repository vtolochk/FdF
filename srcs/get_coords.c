/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:45:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/16 20:23:48 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_and_join(char **big_line, char *line, char **ptr)
{
	char *temp;

	temp = *big_line;
	*big_line = ft_strjoin(*big_line, "\n");
	free(temp);
	temp = *big_line;
	*big_line = ft_strjoin(*big_line, line);
	free(temp);
	free(line);
	ft_free_tab((void **)ptr);
}

static char		*no_valid(char **ptr, char **big_line, char **line, int fd)
{
	ft_free_tab((void **)ptr);
	ft_strdel(big_line);
	ft_strdel(line);
	close(fd);
	return (NULL);
}

static char		*get_line_and_size(int fd, size_t *x, size_t *y)
{
	char		*line;
	char		*temp;
	char		*big_line;
	char		**ptr;
	size_t		valid;

	valid = 0;
	big_line = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		(*y)++;
		ptr = ft_strsplit(line, ' ');
		while (ptr[(*x)])
			(*x)++;
		if (*y == 1)
			valid = *x;
		if (valid != *x)
			return (no_valid(ptr, &big_line, &line, fd));
		free_and_join(&big_line, line, ptr);
	}
	close(fd);
	temp = big_line;
	big_line = ft_strtrim(big_line);
	ft_strdel(&temp);
	return (big_line);
}

static void		get_z_coord(t_fdf_data *data, char *line, t_fdf_point **map)
{
	size_t	i;
	size_t	j;
	char	**lines;
	char	**numbers;

	i = 0;
	lines = ft_strsplit(line, '\n');
	while (i < data->max_y)
	{
		j = 0;
		numbers = ft_strsplit(lines[i], ' ');
		while (j < data->max_x)
		{
			map[i][j].y = (double)i - data->max_y / 2;
			map[i][j].x = (double)j - data->max_x / 2;
			if (numbers)
				map[i][j].z = (double)ft_atoi(numbers[j]);
			j++;
		}
		ft_free_tab((void **)numbers);
		i++;
	}
	ft_free_tab((void**)lines);
}

void			get_coords(t_fdf_data *data, int fd, size_t y, size_t x)
{
	size_t	i;
	char	*big_line;

	i = 0;
	big_line = get_line_and_size(fd, &x, &y);
	if (!big_line)
	{
		ft_printf("Not a valid file\n");
		exit(ERROR);
	}
	data->max_y = y;
	data->max_x = x;
	data->map = (t_fdf_point **)malloc(sizeof(t_fdf_point *) * (y + 1));
	data->map_cpy = (t_fdf_point **)malloc(sizeof(t_fdf_point *) * (y + 1));
	data->map[y] = NULL;
	data->map_cpy[y] = NULL;
	while (i <= y)
		data->map[i++] = (t_fdf_point *)malloc(sizeof(t_fdf_point) * (x));
	i = 0;
	while (i <= y)
		data->map_cpy[i++] = (t_fdf_point *)malloc(sizeof(t_fdf_point) * (x));
	get_z_coord(data, big_line, data->map);
	get_z_coord(data, big_line, data->map_cpy);
	ft_strdel(&big_line);
}
