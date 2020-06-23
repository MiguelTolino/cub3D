/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:53:08 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/12 19:07:33 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static int exist_attributes(int num)
{
	if (num == NUM_CONFIG)
		return (1);
	else
		throw_error("Bad number of elements in configuration");
	return (0);
}

static void save_config(char *line)
{
	char *position;
	
	position = NULL;
	if (position = ft_strnstr(line, "R", ft_strlen(line)))
	{
		g_config.R = save_resolution(line);
		g_config.counter++;
	}
	/*
	 	if (position = ft_strnstr(line, "NO", ft_strlen(line)))
		{
			g_config.NO = save_texture(line);
			g_config.counter++;
		}
	
	 	if (position = ft_strnstr(line, "SO",ft_strlen(line)))
		{
			g_config.SO = save_texture(line);
			g_config.counter++;
		}
		if (position = ft_strnstr(line, "EA",ft_strlen(line)))
		{
			g_config.EA = save_texture(line);
			g_config.counter++;

		}
		if (position = ft_strnstr(line, "WE",ft_strlen(line)))
		{
			g_config.WE = save_texture(line);
			g_config.counter++;

		}
		if (position = ft_strnstr(line, "S",ft_strlen(line)))
		{
			g_config.S = save_texture(line);
			g_config.counter++;
		} 
		*/
	if (position = ft_strnstr(line, "F", ft_strlen(line)))
	{
		g_config.F = save_color(line, position);
		g_config.counter++;
	}
	if (position = ft_strnstr(line, "C", ft_strlen(line)))
	{
		g_config.C = save_color(line, position);
		g_config.counter++;
	}
}

int read_config(char *argv)
{
	int fd;
	char *line;

	g_config.counter = 0;
	if ((fd = open(argv, O_RDONLY)) <= 0)
		throw_error("FD can't be opened");
	while (get_next_line(fd, &line) > 0 && g_config.counter < NUM_CONFIG)
		save_config(line);
	exist_attributes(g_config.counter);
	read_map(fd);
	close(fd);
	return (1);
}