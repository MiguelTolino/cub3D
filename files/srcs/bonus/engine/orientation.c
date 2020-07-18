/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 14:06:15 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 14:07:02 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void		dir_tex(t_engine *en, char dir)
{
	if (dir == 'W')
	{
		en->dir.x = 0;
		en->dir.y = -1;
		en->plane.x = -0.66;
		en->plane.y = 0;
	}
	if (dir == 'E')
	{
		en->dir.x = 0;
		en->dir.y = 1;
		en->plane.x = 0.66;
		en->plane.y = 0;
	}
}

int				orientation(t_engine *en)
{
	char	dir;

	dir = g_config.map.world_map[g_config.pos_x][g_config.pos_y];
	g_config.map.world_map[g_config.pos_x][g_config.pos_y] = '0';
	if (dir == 'N')
	{
		en->dir.x = -1;
		en->dir.y = 0;
		en->plane.x = 0;
		en->plane.y = 0.66;
	}
	if (dir == 'S')
	{
		en->dir.x = 1;
		en->dir.y = 0;
		en->plane.x = 0;
		en->plane.y = -0.66;
	}
	dir_tex(en, dir);
	return (0);
}
