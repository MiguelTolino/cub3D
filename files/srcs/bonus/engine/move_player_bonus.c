/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:40:33 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/22 18:12:25 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int		move_foward(t_engine *en)
{
	if (g_config.map.world_map[(int)(en->pos.x + en->dir.x *
	en->move_speed)][(int)en->pos.y] == '0')
		en->pos.x += en->dir.x * en->move_speed;
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y + en->dir.y *
	en->move_speed)] == '0')
		en->pos.y += en->dir.y * en->move_speed;
	return (0);
}

int		move_backward(t_engine *en)
{
	if (g_config.map.world_map[(int)(en->pos.x - en->dir.x *
	en->move_speed)][(int)en->pos.y] == '0')
		en->pos.x -= en->dir.x * en->move_speed;
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y -
	en->dir.y * en->move_speed)] == '0')
		en->pos.y -= en->dir.y * en->move_speed;
	return (0);
}

int		move_left(t_engine *en)
{
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y +
	en->dir.x * en->move_speed)] == '0')
		en->pos.y += en->dir.x * en->move_speed;
	if (g_config.map.world_map[(int)(en->pos.x - en->dir.y *
	en->move_speed)][(int)en->pos.y] == '0')
		en->pos.x -= en->dir.y * en->move_speed;
	return (0);
}

int		move_right(t_engine *en)
{
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y -
	en->dir.x * en->move_speed)] == '0')
		en->pos.y -= en->dir.x * en->move_speed;
	if (g_config.map.world_map[(int)(en->pos.x + en->dir.y *
	en->move_speed)][(int)en->pos.y] == '0')
		en->pos.x += en->dir.y * en->move_speed;
	return (0);
}
