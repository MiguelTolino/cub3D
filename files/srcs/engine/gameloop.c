/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:57:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/26 00:35:57 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void verLine(int x, int drawStart, int drawEnd, int color, void *mlx_ptr, void *mlx_win)
{
	int i = drawStart;
	while (i < drawEnd)
		mlx_pixel_put(mlx_ptr, mlx_win, x, i++, color);
}

int gameloop(t_mlx *mlx, t_game player)
{
	int x;

	while (1 /*!done()*/)
	{
		x = 0;
		while (x < g_config.R.x)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / (double)g_config.R.x - 1; //x-coordinate in camera space
			double rayDirX = player.dir.x + player.plane.x * cameraX;
			double rayDirY = player.dir.y + player.plane.y * cameraX;

			//which box of the map we're in
			int mapX = (int)player.pos.x;
			int mapY = (int)player.pos.y;

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = abs(1 / rayDirX);
			double deltaDistY = abs(1 / rayDirY);
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side;	 //was a NS or a EW wall hit?

			//calculate step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (player.pos.x - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - player.pos.x) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (player.pos.y - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - player.pos.y) * deltaDistY;
			}

			//perform DDA
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if (g_config.map.world_map[mapX][mapY] > 0)
					hit = 1;
			}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if (side == 0)
				perpWallDist = (mapX - player.pos.x + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - player.pos.y + (1 - stepY) / 2) / rayDirY;

			//Calculate height of line to draw on screen
			int lineHeight = (int)(g_config.R.x / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + g_config.R.y / 2;
			if (drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + g_config.R.y / 2;
			if (drawEnd >= g_config.R.y)
				drawEnd = g_config.R.y - 1;
			//choose wall color
			int color;
			switch (g_config.map.world_map[mapX][mapY])
			{
			case 1:
				color = 16711680;
				break; //red
			case 2:
				color = 65280;
				break; //green
			case 3:
				color = 255;
				break; //blue
			case 4:
				color = 16777215;
				break; //white
			default:
				color = 16776960;
				break; //yellow
			}
			//give x and y sides different brightness
			if (side == 1)
			{
				color = color / 2;
			}
			//draw the pixels of the stripe as a vertical line
			verLine(x, drawStart, drawEnd, color, mlx->ptr, mlx->win);
			x++;
		}
	}
}