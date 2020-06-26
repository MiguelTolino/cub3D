/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 18:58:31 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/25 14:06:46 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void fill_map(char **map)
{
	int i;
	ssize_t len;
	char padding;
	char *aux;

	i = 0;
	padding = ' ';
	while (i < g_config.map.n_row)
	{
		len = g_config.map.n_col - ft_strlen(map[i]);
		if (len)
		{
			aux = ft_strjoin(map[i], pad_right(padding, len));
			free(map[i]);
			map[i] = aux;
		}
		i++;
	}
}

char **parse_map(char *buff)
{
	char **map;
	int i;
	int j;
	int trigger;
	char **aux;

	trigger = 0;
	map = ft_split(g_config.map.buff, '\n');
	fill_map(map);
	i = 0;
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
				break;
			}
			j++;
		}
		if (trigger)
			break;
		i++;
	}
	aux = copy_matrix(g_config.map.n_row, map);
	if (!check_map(aux, i, j))
	{
		//FIXME free_str(aux); Liberar AUX
		return (map);
	}
	else
		throw_error("Map is not closed");
}

int check_map(char **map, int row, int col)
{
	char c;
	int ok;

	if (row < 0 || col < 0 || row >= g_config.map.n_row || col >= g_config.map.n_col)
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
