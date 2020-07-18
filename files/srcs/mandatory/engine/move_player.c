/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:47:21 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 02:04:14 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		move_foward(t_engine *en)
{
	if (g_config.map.world_map[(int)(en->pos.x + en->dir.x *
	MOVE_SPEED)][(int)en->pos.y] == '0')
		en->pos.x += en->dir.x * MOVE_SPEED;
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y + en->dir.y
	* MOVE_SPEED)] == '0')
		en->pos.y += en->dir.y * MOVE_SPEED;
}

void		move_backward(t_engine *en)
{
	if (g_config.map.world_map[(int)(en->pos.x - en->dir.x *
	MOVE_SPEED)][(int)en->pos.y] == '0')
		en->pos.x -= en->dir.x * MOVE_SPEED;
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y - en->dir.y *
	MOVE_SPEED)] == '0')
		en->pos.y -= en->dir.y * MOVE_SPEED;
}

void		move_left(t_engine *en)
{
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y + en->dir.x *
	MOVE_SPEED)] == '0')
		en->pos.y += en->dir.x * MOVE_SPEED;
	if (g_config.map.world_map[(int)(en->pos.x - en->dir.y *
	MOVE_SPEED)][(int)en->pos.y] == '0')
		en->pos.x -= en->dir.y * MOVE_SPEED;
}

void		move_right(t_engine *en)
{
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y - en->dir.x *
	MOVE_SPEED)] == '0')
		en->pos.y -= en->dir.x * MOVE_SPEED;
	if (g_config.map.world_map[(int)(en->pos.x + en->dir.y *
	MOVE_SPEED)][(int)en->pos.y] == '0')
		en->pos.x += en->dir.y * MOVE_SPEED;
}
