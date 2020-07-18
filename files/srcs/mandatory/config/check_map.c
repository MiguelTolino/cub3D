/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:10:05 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 11:54:45 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void		fill_map(char **map)
{
	int			i;
	ssize_t		len;
	char		padding;
	char		*aux;
	char		*pad;

	i = 0;
	padding = ' ';
	while (i < g_config.map.n_row)
	{
		len = g_config.map.n_col - ft_strlen(map[i]);
		if (len)
		{
			pad = pad_right(padding, len);
			aux = ft_strjoin(map[i], pad);
			free(map[i]);
			map[i] = aux;
			free(pad);
		}
		i++;
	}
}

static void		locate_position(char **map)
{
	int i;
	int j;
	int trigger;

	i = 0;
	trigger = 0;
	while (i < g_config.map.n_row)
	{
		j = 0;
		while (j < g_config.map.n_col)
		{
			if (ft_strchr("NWES", map[i][j]))
			{
				trigger++;
				g_config.pos_x = i;
				g_config.pos_y = j;
			}
			j++;
		}
		i++;
	}
	if (trigger != 1)
		throw_error("Wrong number of positions");
}

int				check_map(char **map, int row, int col)
{
	char		c;
	int			ok;

	if (row < 0 || col < 0 || row >= g_config.map.n_row
	|| col >= g_config.map.n_col)
		return (1);
	c = map[row][col];
	if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	map[row][col] = '3';
	ok = check_map(map, row, col - 1);
	ok = ok == 0 ? check_map(map, row, col + 1) : ok;
	ok = ok == 0 ? check_map(map, row - 1, col) : ok;
	ok = ok == 0 ? check_map(map, row + 1, col) : ok;
	return (ok);
}

char			**parse_map(void)
{
	char		**map;
	char		**aux;

	map = ft_split(g_config.map.buff, '\n');
	fill_map(map);
	locate_position(map);
	aux = copy_matrix(g_config.map.n_row, map);
	if (check_map(aux, g_config.pos_x, g_config.pos_y))
		throw_error("Map is not closed");
	free_str(aux);
	return (map);
}
