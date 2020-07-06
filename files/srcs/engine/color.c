/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:33:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/06 11:34:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int get_color(t_engine *en)
{
	//choose wall color
	int color;
	if (g_config.map.world_map[en->map_x][en->map_y] == '1')
	{
		color = 16712447;
	}
	if (g_config.map.world_map[en->map_x][en->map_y] == '2')
	{
		color = 255;
	}
	if (en->side == 1)
		color = color / 2;
	return (color);
}