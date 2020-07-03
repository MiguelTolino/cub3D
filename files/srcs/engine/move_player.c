/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:40:33 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/03 14:22:14 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int rotate_right(t_engine *en)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = en->dir.x;
	en->dir.x = en->dir.x * cos(-ROT_SPEED) - en->dir.y * sin(-ROT_SPEED);
	en->dir.y = old_dir_x * sin(-ROT_SPEED) + en->dir.y * cos(-ROT_SPEED);
	old_plane_x = en->plane.x;
	en->plane.x = en->plane.x * cos(-ROT_SPEED) - en->plane.y * sin(-ROT_SPEED);
	en->plane.y = old_plane_x * sin(-ROT_SPEED) + en->plane.y * cos(-ROT_SPEED);
}

static int rotate_left(t_engine *en)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = en->dir.x;
	en->dir.x = en->dir.x * cos(ROT_SPEED) - en->dir.y * sin(ROT_SPEED);
	en->dir.y = old_dir_x * sin(ROT_SPEED) + en->dir.y * cos(ROT_SPEED);
	old_plane_x = en->plane.x;
	en->plane.x = en->plane.x * cos(ROT_SPEED) - en->plane.y * sin(ROT_SPEED);
	en->plane.y = old_plane_x * sin(ROT_SPEED) + en->plane.y * cos(ROT_SPEED);
}

static int move_foward(t_engine *en)
{
	if (g_config.map.world_map[(int)(en->pos.x + en->dir.x * MOVE_SPEED)][(int)en->pos.y] == '0')
		en->pos.x += en->dir.x * MOVE_SPEED;
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y + en->dir.y * MOVE_SPEED)] == '0')
		en->pos.y += en->dir.y * MOVE_SPEED;
}

static int move_backward(t_engine *en)
{
	if (g_config.map.world_map[(int)(en->pos.x + en->dir.x * MOVE_SPEED)][(int)en->pos.y] == '0')
		en->pos.x -= en->dir.x * MOVE_SPEED;
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y + en->dir.y * MOVE_SPEED)] == '0')
		en->pos.y -= en->dir.y * MOVE_SPEED;
}

static int move_left(t_engine *en)
{
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y + en->dir.x * MOVE_SPEED)] == '0')
		en->pos.y += en->dir.x * MOVE_SPEED;
	if (g_config.map.world_map[(int)(en->pos.x - en->dir.y * MOVE_SPEED)][(int)en->pos.y] == '0')
		en->pos.x -= en->dir.y * MOVE_SPEED;
}

static int move_right(t_engine *en)
{
	if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y + en->dir.x * MOVE_SPEED)] == '0')
		en->pos.y -= en->dir.x * MOVE_SPEED;
	if (g_config.map.world_map[(int)(en->pos.x - en->dir.y * MOVE_SPEED)][(int)en->pos.y] == '0')
		en->pos.x += en->dir.y * MOVE_SPEED;
}

int read_keys(int keycode, t_engine *en)
{
	//move forward if no wall in front of you
	if (keycode == KEY_W)
	{
		move_foward(en);
		printf("PosX: %f\t", en->pos.x);
		printf("PosY: %f\n", en->pos.y);
	}
	//move backwards if no wall behind you
	if (keycode == KEY_S)
	{
		move_backward(en);
		printf("PosX: %f\t", en->pos.x);
		printf("PosY: %f\n", en->pos.y);
	}
	if (keycode == KEY_RIGHT)
	{
		//both camera direction and camera plane must be rotated
		rotate_right(en);
		printf("DirX: %f\t", en->dir.x);
		printf("DirY: %f\n", en->dir.y);
		printf("PlaneX: %f\t", en->plane.x);
		printf("PlaneY: %f\n", en->plane.y);
	}
	//rotate to the left
	if (keycode == KEY_LEFT)
	{
		//both camera direction and camera plane must be rotated
		rotate_left(en);
		printf("DirX: %f\t", en->dir.x);
		printf("DirY: %f\n", en->dir.y);
		printf("PlaneX: %f\t", en->plane.x);
		printf("PlaneY: %f\n ", en->plane.y);
	}
	if (keycode == KEY_A)
	{
		move_left(en);
		printf("PosX: %f\t", en->pos.x);
		printf("PosY: %f\n", en->pos.y);
		}
	if (keycode == KEY_D)
	{
		move_right(en);
		printf("PosX: %f\t", en->pos.x);
		printf("PosY: %f\n", en->pos.y);
	}
	if (keycode == KEY_ESC)
		exit(0);
	mlx_clear_window(en->mlx.ptr, en->mlx.win);
	gameloop(en);
}