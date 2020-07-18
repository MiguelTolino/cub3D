/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:15:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 02:21:14 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		dir_we(t_engine *en, char dir)
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
	dir_we(en, dir);
	return (0);
}

void			open_textures(t_engine *en)
{
	en->mlx.texture[0].data = (int*)mlx_get_data_addr(en->mlx.texture[0].ptr,
	&en->mlx.texture[0].bpp, &en->mlx.texture[0].size_line,
	&en->mlx.texture[0].endian);
	en->mlx.texture[1].data = (int*)mlx_get_data_addr(en->mlx.texture[1].ptr,
	&en->mlx.texture[1].bpp, &en->mlx.texture[1].size_line,
	&en->mlx.texture[1].endian);
	en->mlx.texture[2].data = (int*)mlx_get_data_addr(en->mlx.texture[2].ptr,
	&en->mlx.texture[2].bpp, &en->mlx.texture[2].size_line,
	&en->mlx.texture[2].endian);
	en->mlx.texture[3].data = (int*)mlx_get_data_addr(en->mlx.texture[3].ptr,
	&en->mlx.texture[3].bpp, &en->mlx.texture[3].size_line,
	&en->mlx.texture[3].endian);
	en->mlx.texture[4].data = (int*)mlx_get_data_addr(en->mlx.texture[4].ptr,
	&en->mlx.texture[4].bpp, &en->mlx.texture[4].size_line,
	&en->mlx.texture[4].endian);
}
