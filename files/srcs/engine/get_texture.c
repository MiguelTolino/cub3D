/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:44:15 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/12 12:52:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int get_side(t_engine *en)
{
	int num;

	if (en->ray_dir.x < 0 && en->side == 0)
		num = 0;
	if (en->ray_dir.x > 0 && en->side == 0)
		num = 1;
	if (en->ray_dir.y < 0 && en->side == 1)
		num = 2;
	if (en->ray_dir.y > 0 && en->side == 1)
		num = 3;
	return (num);
}

int get_texture(t_engine *en)
{
	en->tex.num = get_side(en);
	if (en->side == 0)
		en->tex.wall_x = en->pos.y + en->perp_wall_dist * en->ray_dir.y;
	else
		en->tex.wall_x = en->pos.x + en->perp_wall_dist * en->ray_dir.x;
	en->tex.wall_x -= floor(en->tex.wall_x);
	en->tex.x = (int)(en->tex.wall_x * (double)(en->mlx.texture[en->tex.num].width));
	if (en->side == 0 && en->ray_dir.x > 0)
		en->tex.x = en->mlx.texture[en->tex.num].width - en->tex.x - 1;
	if (en->side == 1 && en->ray_dir.y < 0)
		en->tex.x = en->mlx.texture[en->tex.num].width - en->tex.x - 1;
	en->tex.step = 1.0 * en->mlx.texture[en->tex.num].height / en->line_height;
	en->tex.pos = (en->draw_start - g_config.R.y / 2 + en->line_height / 2) * en->tex.step;
	return (0);
}
/* 
int floor_casting(t_engine *en)
{
	int y;
	int p;
	float pos_z;
	float row_distance;

	y = 0;
	 //FLOOR CASTING
    while (y < g_config.R.y)
    {
      // rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
      float rayDirX0 = dirX - planeX;
      float rayDirY0 = dirY - planeY;
      float rayDirX1 = dirX + planeX;
      float rayDirY1 = dirY + planeY;

      // Current y position compared to the center of the screen (the horizon)
      p = y - g_config.R.y / 2;

      // Vertical position of the camera.
      pos_z = 0.5 * g_config.R.y;

      // Horizontal distance from the camera to the floor for the current row.
      // 0.5 is the z position exactly in the middle between floor and ceiling.
      row_distance = pos_z / p;

      // calculate the real world step vector we have to add for each x (parallel to camera plane)
      // adding step by step avoids multiplications with a weight in the inner loop
      float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / screenWidth;
      float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / screenWidth;

      // real world coordinates of the leftmost column. This will be updated as we step to the right.
      float floorX = posX + rowDistance * rayDirX0;
      float floorY = posY + rowDistance * rayDirY0;

      for(int x = 0; x < screenWidth; ++x)
      {
        // the cell coord is simply got from the integer parts of floorX and floorY
        int cellX = (int)(floorX);
        int cellY = (int)(floorY);

        // get the texture coordinate from the fractional part
        int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
        int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

        floorX += floorStepX;
        floorY += floorStepY;

        // choose texture and draw the pixel
        int floorTexture = 3;
        int ceilingTexture = 6;
        Uint32 color;

        // floor
        color = texture[floorTexture][texWidth * ty + tx];
        color = (color >> 1) & 8355711; // make a bit darker
        buffer[y][x] = color;

        //ceiling (symmetrical, at screenHeight - y - 1 instead of y)
        color = texture[ceilingTexture][texWidth * ty + tx];
        color = (color >> 1) & 8355711; // make a bit darker
        buffer[screenHeight - y - 1][x] = color;
      }
    }
} */
