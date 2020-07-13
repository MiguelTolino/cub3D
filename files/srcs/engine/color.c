/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:33:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/13 11:00:08 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int get_side(t_engine *en)
{
	int color;

	if (en->ray_dir.x < 0 && en->side == 0)
		color = rgb_int(255,0,0);
	if (en->ray_dir.x > 0 && en->side == 0)
		color = rgb_int(0,255,0);
	if (en->ray_dir.y < 0 && en->side == 1)
		color = rgb_int(255, 0, 255);
	if (en->ray_dir.y > 0 && en->side == 1)
		color = rgb_int(255, 255, 255);
	return (color);
}
int get_color(t_engine *en)
{
	int color;
	if (g_config.map.world_map[en->map_x][en->map_y] == '1')
		color = get_side(en);
	if (g_config.map.world_map[en->map_x][en->map_y] == '2')
		color = 255;
 	if (en->side == 1)
		color = color / 2;
	return (color);
}