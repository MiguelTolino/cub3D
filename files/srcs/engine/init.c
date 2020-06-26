/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:42:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/26 11:32:04 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int orientation(t_cam *cam)
{
	char dir;
	dir = g_config.map.world_map[g_config.pos_x][g_config.pos_y];
	g_config.map.world_map[g_config.pos_x][g_config.pos_y] = '0';
	if (dir == 'N')
	{
		cam->dir.x = 0;
		cam->dir.y = 0;
	}
	if (dir == 'S')
	{
		cam->dir.x = 0;
		cam->dir.y = 0;
	}
	if (dir == 'W')
	{
		cam->dir.x = 0;
		cam->dir.y = 0;
	}
	if (dir == 'E')
	{
		cam->dir.x = 0;
		cam->dir.y = 0;
	}

	return (0);
}

t_cam init()
{
	t_cam cam;
	
	cam.pos.x = g_config.pos_x;
	cam.pos.y = g_config.pos_y;
	orientation(&cam);
	cam.dir.x = -1;
	cam.dir.y = 0;
	cam.plane.x = 0;
	cam.plane.y = 0.66;

	return (cam);
}