/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:10:26 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/21 14:32:18 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void		save_textures2(char *line, int limit, char *position)
{
	if ((position = ft_strnstr(line, "WE", ft_strlen(line))) != NULL &&
	!limit && *(position + 2) == ' ')
	{
		g_config.we = save_texture(line);
		g_config.used[6] = 1;
		limit = 1;
	}
	if ((position = ft_strnstr(line, "S", ft_strlen(line))) != NULL &&
	!limit && *(position + 1) == ' ')
	{
		g_config.s = save_texture(line);
		g_config.used[7] = 1;
		limit = 1;
	}
	if ((position = ft_strnstr(line, "R", ft_strlen(line))) != NULL && !limit &&
	*(position + 1) == ' ')
	{
		g_config.r = save_resolution(line);
		g_config.used[0] = 1;
		limit = 1;
	}
}

static void		save_textures1(char *line, int limit, char *position)
{
	if ((position = ft_strnstr(line, "NO", ft_strlen(line))) != NULL &&
	!limit && *(position + 2) == ' ')
	{
		g_config.no = save_texture(line);
		g_config.used[3] = 1;
		limit = 1;
	}
	else if ((position = ft_strnstr(line, "SO", ft_strlen(line))) != NULL &&
	!limit && *(position + 2) == ' ')
	{
		g_config.so = save_texture(line);
		g_config.used[4] = 1;
		limit = 1;
	}
	else if ((position = ft_strnstr(line, "EA", ft_strlen(line))) != NULL &&
	!limit && *(position + 2) == ' ')
	{
		g_config.ea = save_texture(line);
		g_config.used[5] = 1;
		limit = 1;
	}
}

static void		save_config(char *line)
{
	char	*position;
	int		limit;

	position = NULL;
	limit = 0;
	if ((position = ft_strnstr(line, "F", ft_strlen(line))) != NULL && !limit &&
	*(position + 1) == ' ')
	{
		g_config.f = save_color(line, position);
		g_config.used[1] = 1;
		limit = 1;
	}
	if ((position = ft_strnstr(line, "C", ft_strlen(line))) != NULL && !limit &&
	*(position + 1) == ' ')
	{
		g_config.c = save_color(line, position);
		g_config.used[2] = 1;
		limit = 1;
	}
	save_textures1(line, limit, position);
	save_textures2(line, limit, position);
	if (!line[0])
		return ;
	g_config.counter++;
}

int				read_config(char *argv)
{
	int		fd;
	char	*line;
	int		i;

	g_config.counter = 0;
	i = 0;
	g_config.used = calloc(NUM_CONFIG, sizeof(int));
	if ((fd = open(argv, O_RDONLY)) <= 0)
		throw_error("FD can't be opened");
	while (get_next_line(fd, &line) > 0 && g_config.counter < NUM_CONFIG)
	{
		save_config(line);
		free(line);
	}
	while (i < NUM_CONFIG)
	{
		if (g_config.used[i++] == 0)
			throw_error("Configuration is wrong");
	}
	if (g_config.counter != NUM_CONFIG)
		throw_error("Bad number of elements in configuration");
	read_map(fd);
	free(line);
	close(fd);
	return (1);
}
