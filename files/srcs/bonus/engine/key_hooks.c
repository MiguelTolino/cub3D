/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 14:02:04 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/22 13:26:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void		rotate_right(t_engine *en)
{
	en->old_dir_x = en->dir.x;
	en->dir.x = en->dir.x * cos(-en->rot_speed) - en->dir.y *
	sin(-en->rot_speed);
	en->dir.y = en->old_dir_x * sin(-en->rot_speed) + en->dir.y *
	cos(-en->rot_speed);
	en->old_plane_x = en->plane.x;
	en->plane.x = en->plane.x * cos(-en->rot_speed) - en->plane.y *
	sin(-en->rot_speed);
	en->plane.y = en->old_plane_x * sin(-en->rot_speed) + en->plane.y *
	cos(-en->rot_speed);
}

void		rotate_left(t_engine *en)
{
	en->old_dir_x = en->dir.x;
	en->dir.x = en->dir.x * cos(en->rot_speed) - en->dir.y *
	sin(en->rot_speed);
	en->dir.y = en->old_dir_x * sin(en->rot_speed) + en->dir.y *
	cos(en->rot_speed);
	en->old_plane_x = en->plane.x;
	en->plane.x = en->plane.x * cos(en->rot_speed) - en->plane.y *
	sin(en->rot_speed);
	en->plane.y = en->old_plane_x * sin(en->rot_speed) + en->plane.y *
	cos(en->rot_speed);
}

int		movement(t_engine *en)
{
	if (en->k_buff.up)
		move_foward(en);
	if (en->k_buff.down)
		move_backward(en);
	if (en->k_buff.left)
		move_left(en);
	if (en->k_buff.right)
		move_right(en);
	if (en->k_buff.rot_left)
		rotate_left(en);
	if (en->k_buff.rot_right)
		rotate_right(en);
	if (en->k_buff.esc)
		exit_game(en);
	return (0);
}

int		key_press(int keycode, t_engine *en)
{
	if (keycode == KEY_W)
		en->k_buff.up = 1;
	if (keycode == KEY_S)
		en->k_buff.down = 1;
	if (keycode == KEY_RIGHT)
		en->k_buff.rot_right = 1;
	if (keycode == KEY_LEFT)
		en->k_buff.rot_left = 1;
	if (keycode == KEY_A)
		en->k_buff.left = 1;
	if (keycode == KEY_D)
		en->k_buff.right = 1;
	if (keycode == KEY_ESC)
		en->k_buff.esc = 1;
	return (0);
}

int		key_release(int keycode, t_engine *en)
{
	if (keycode == KEY_W)
		en->k_buff.up = 0;
	if (keycode == KEY_S)
		en->k_buff.down = 0;
	if (keycode == KEY_RIGHT)
		en->k_buff.rot_right = 0;
	if (keycode == KEY_LEFT)
		en->k_buff.rot_left = 0;
	if (keycode == KEY_A)
		en->k_buff.left = 0;
	if (keycode == KEY_D)
		en->k_buff.right = 0;
	return (0);
}
