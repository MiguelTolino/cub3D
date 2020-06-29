/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:57:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/29 19:39:23 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int read_keys(int keycode, t_engine *en)
{
	//move forward if no wall in front of you
	if (keycode == KEY_W)
	{
		if (g_config.map.world_map[(int)(en->pos.x + en->dir.x * MOVE_SPEED)][(int)en->pos.y] == '0')
			en->pos.x += en->dir.x * MOVE_SPEED;
		if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y + en->dir.y * MOVE_SPEED)] == '0')
			en->pos.y += en->dir.y * MOVE_SPEED;
		printf("PosX: %f\n", en->pos.x);
		printf("PosY: %f\n", en->pos.y);
	}
	//move backwards if no wall behind you
	if (keycode == KEY_S)
	{
		if (g_config.map.world_map[(int)(en->pos.x + en->dir.x * MOVE_SPEED)][(int)en->pos.y] == '0')
			en->pos.x -= en->dir.x * MOVE_SPEED;
		if (g_config.map.world_map[(int)en->pos.x][(int)(en->pos.y + en->dir.y * MOVE_SPEED)] == '0')
			en->pos.y -= en->dir.y * MOVE_SPEED;
	}
	/*	//rotate to the right
	if (keycode == KEY_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if (keycode == KEY_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	} */
}
void verLine(t_engine en, t_mlx *mlx, int x)
{
	int i = en.draw_start;
	while (i < en.draw_end)
		mlx_pixel_put(mlx->ptr, mlx->win, x, i++, en.color);
}
int get_color(t_engine en)
{
	//choose wall color
	int color;
	if (g_config.map.world_map[en.map_x][en.map_y] == '1')
	{
		color = 16712447;
	}
	return (color);
}

int gameloop(t_mlx *mlx, t_engine en)
{
	int x;

	while (1 /*FUNCTION STOP*/)
	{
		x = 0;
		while (x < g_config.R.x)
		{
			//Calculated ray position and direction
			en.camera.x = 2 * x / (double)g_config.R.x - 1; //Cordinate x in screen 0,1,-1
			en.ray_dir.x = en.dir.x + en.plane.x * en.camera.x;
			en.ray_dir.y = en.dir.y + en.plane.y * en.camera.x;

			//which box of the map we are in
			en.map_x = (int)en.pos.x;
			en.map_y = (int)en.pos.y;

			en.delta_dist.x = abs(1 / en.ray_dir.x);
			en.delta_dist.y = abs(1 / en.ray_dir.y);

			en.hit = 0;

			//Calcula steps and initial side_dist
			if (en.ray_dir.x < 0)
			{
				en.step_x = -1;
				en.side_dist.x = (en.pos.x - en.map_x) * en.delta_dist.x;
			}
			else
			{
				en.step_x = 1;
				en.side_dist.x = (en.map_x + 1.0 - en.pos.x) * en.delta_dist.x;
			}
			if (en.ray_dir.y < 0)
			{
				en.step_y = -1;
				en.side_dist.y = (en.pos.y - en.map_y) * en.delta_dist.y;
			}
			else
			{
				en.step_y = 1;
				en.side_dist.y = (en.map_y + 1.0 - en.pos.y) * en.delta_dist.y;
			}

			//perform DDA
			while (en.hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (en.side_dist.x < en.side_dist.y)
				{
					en.side_dist.x += en.delta_dist.x;
					en.map_x += en.step_x;
					en.side = 0;
				}
				else
				{
					en.side_dist.y += en.delta_dist.y;
					en.map_y += en.step_y;
					en.side = 1;
				}
				//Check if ray has hit a wall
				if (g_config.map.world_map[en.map_x][en.map_y] > '0')
					en.hit = 1;
			}
			if (en.side == 0)
				en.perp_wall_dist = (en.map_x - en.pos.x + (1 - en.step_x) / 2) / en.ray_dir.x;
			else
				en.perp_wall_dist = (en.map_y - en.pos.y + (1 - en.step_y) / 2) / en.ray_dir.y;

			//Calculate height of line to draw on screen
			en.line_height = (int)(g_config.R.y / en.perp_wall_dist);

			//calculate lowest and highest pixel to fill in current stripe
			en.draw_start = -(en.line_height) / 2 + g_config.R.y / 2;
			if (en.draw_start < 0)
				en.draw_start = 0;
			en.draw_end = en.line_height / 2 + g_config.R.y / 2;
			if (en.draw_end >= g_config.R.y)
				en.draw_end = g_config.R.y - 1;

			en.color = get_color(en);
			//give x and y sides different brightness
			if (en.side == 1)
				en.color = en.color / 2;

			verLine(en, mlx, x);
			mlx_key_hook(mlx->win, read_keys, &en);
			x++;
		}
	}
}