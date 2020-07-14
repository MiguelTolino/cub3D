/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:53:08 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/14 19:19:26 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void	save_config(char *line)
{
	char	*position;

	position = NULL;
	if (position = ft_strnstr(line, "R", ft_strlen(line)))
		g_config.R = save_resolution(line);
	if (position = ft_strnstr(line, "NO", ft_strlen(line)))
		g_config.NO = save_texture(line);
	if (position = ft_strnstr(line, "SO", ft_strlen(line)))
		g_config.SO = save_texture(line);
	if (position = ft_strnstr(line, "EA", ft_strlen(line)))
		g_config.EA = save_texture(line);
	if (position = ft_strnstr(line, "WE", ft_strlen(line)))
		g_config.WE = save_texture(line);
	if (position = ft_strnstr(line, "S", ft_strlen(line)))
		g_config.S = save_texture(line);
	if (position = ft_strnstr(line, "F", ft_strlen(line)))
		if (position = ft_strnstr(line, "FT", ft_strlen(line)))
			g_config.FT = save_texture(line);
		else
			g_config.F = save_color(line, position);
	if (position = ft_strnstr(line, "C", ft_strlen(line)))
		if (position = ft_strnstr(line, "CT", ft_strlen(line)))
			g_config.CT = save_texture(line);
		else
			g_config.C = save_color(line, position);
}

int			read_config(char *argv)
{
	int		fd;
	char	*line;

	g_config.counter = -1;
	if ((fd = open(argv, O_RDONLY)) <= 0)
		throw_error("FD can't be opened");
	while (get_next_line(fd, &line) > 0 && g_config.counter < NUM_CONFIG)
		save_config(line);
	if (g_config.counter != NUM_CONFIG)
		throw_error("Bad number of elements in configuration");
	read_map(fd);
	close(fd);
	return (1);
}
