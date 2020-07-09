/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:42:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/09 14:29:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int orientation(t_engine *en)
{
	char dir;
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
	return (0);
}

static t_key_buff init_key_buff()
{
	t_key_buff buff;
	
	buff.up = 0;
	buff.down = 0;
	buff.left = 0;
	buff.right = 0;
	buff.left = 0;
	buff.rot_left = 0;
	buff.rot_right = 0;
	buff.esc = 0;
	return (buff);
}

static t_fps  init_fps()
{
	t_fps fps;
	
	fps.time = 0;
	fps.old_time = 0;
	fps.counter = 0;
	fps.max = 0;
	fps.min = 1000;
	fps.average = 0;
	fps.num = 0;
	return (fps);
}

void init(t_engine *en)
{
	en->pos.x = g_config.pos_x;
	en->pos.y = g_config.pos_y;
	orientation(en);
	en->k_buff = init_key_buff();
	en->fps = init_fps();
}