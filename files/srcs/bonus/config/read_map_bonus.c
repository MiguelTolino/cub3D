/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 09:10:06 by miguel            #+#    #+#             */
/*   Updated: 2020/07/17 23:20:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_bonus.h"

int			is_map(char *line) //TODO Considerate another number for bonus
{
	unsigned int i;
	unsigned int position;

	i = 0;
	position = 0;
	if (!*line)
		return (0);
 	while (line[i] == ' ' || line[i] == '1' || line[i] == '2' || line[i] == '0'
	|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W' ||
	line[i] == '3' || line[i] == '4' || line[i] == '5')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			position++;
		i++;
	}
	if (position > 1)
		throw_error("Wrong number of Initial Positions");
	if (i == ft_strlen(line))
		return (1);
	else
		return (0);
}

void		read_map(int fd)
{
	char	*line;
	int		c_len;
	int		end;
	char	*aux;

	g_config.map.n_col = 0;
	g_config.map.n_row = 0;
	g_config.map.buff = ft_strdup("");
	while ((end = get_next_line(fd, &line)) >= 0)
	{
		if (is_map(line))
		{
			aux = ft_strjoin(g_config.map.buff, line);
			free(g_config.map.buff);
			g_config.map.buff = aux;
			if (end)
			{
				aux = ft_strjoin(g_config.map.buff, "\n");
				free(g_config.map.buff);
				g_config.map.buff = aux;
			}
			g_config.map.n_row++;
			c_len = ft_strlen(line);
			if (c_len > g_config.map.n_col)
				g_config.map.n_col = c_len;
		}
		free(line);
		if (!end)
			break ;
	}
	g_config.map.world_map = parse_map();
	free(g_config.map.buff);
}
