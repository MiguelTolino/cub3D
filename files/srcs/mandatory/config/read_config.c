/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:10:26 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 02:41:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void		save_textures(char *line, int limit, char *position)
{
	if ((position = ft_strnstr(line, "NO", ft_strlen(line))) != NULL && !limit)
	{
		g_config.no = save_texture(line);
		limit = 1;
	}
	if ((position = ft_strnstr(line, "SO", ft_strlen(line))) != NULL && !limit)
	{
		g_config.so = save_texture(line);
		limit = 1;
	}
	if ((position = ft_strnstr(line, "EA", ft_strlen(line))) != NULL && !limit)
	{
		g_config.ea = save_texture(line);
		limit = 1;
	}
	if ((position = ft_strnstr(line, "WE", ft_strlen(line))) != NULL && !limit)
	{
		g_config.we = save_texture(line);
		limit = 1;
	}
	if ((position = ft_strnstr(line, "S", ft_strlen(line))) != NULL && !limit)
	{
		g_config.s = save_texture(line);
		limit = 1;
	}
}

static void		save_config(char *line)
{
	char	*position;
	int		limit;

	position = NULL;
	limit = 0;
	if ((position = ft_strnstr(line, "R", ft_strlen(line))) != NULL && !limit)
	{
		g_config.r = save_resolution(line);
		limit = 1;
	}
	if ((position = ft_strnstr(line, "F", ft_strlen(line))) != NULL && !limit)
	{
		g_config.f = save_color(line, position);
		limit = 1;
	}
	if ((position = ft_strnstr(line, "C", ft_strlen(line))) != NULL && !limit)
	{
		g_config.c = save_color(line, position);
		limit = 1;
	}
	save_textures(line, limit, position);
}

int				read_config(char *argv)
{
	int		fd;
	char	*line;

	g_config.counter = 0;
	if ((fd = open(argv, O_RDONLY)) <= 0)
		throw_error("FD can't be opened");
	while (get_next_line(fd, &line) > 0 && g_config.counter < NUM_CONFIG)
	{
		save_config(line);
		free(line);
	}
	if (g_config.counter != NUM_CONFIG)
		throw_error("Bad number of elements in configuration");
	read_map(fd);
	free(line);
	close(fd);
	return (1);
}
