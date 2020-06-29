/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:42:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/29 12:37:16 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int orientation(t_engine *en)
{
	char dir;
	dir = g_config.map.world_map[g_config.pos_x][g_config.pos_y];
	g_config.map.world_map[g_config.pos_x][g_config.pos_y] = '0';
	if (dir == 'N')
	{
		en->dir.y = 0;
		en->dir.x = -1;
	}
	if (dir == 'S')
	{
		en->dir.y = 0;
		en->dir.x = 1;
	}
	if (dir == 'W')
	{
		en->dir.x = -1;
		en->dir.y = -1;
	}
	if (dir == 'E')
	{
		en->dir.x = 1;
		en->dir.y = 1;
	}
	return (0);
}

void init(t_engine *en)
{
	en->pos.x = g_config.pos_x;
	en->pos.y = g_config.pos_y;
	orientation(en);
	en->plane.x = 0;
	en->plane.y = 0.66;
}