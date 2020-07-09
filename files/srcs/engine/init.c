/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:42:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/09 19:13:40 by mmateo-t         ###   ########.fr       */
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

static t_texture init_texture(t_engine *en)
{
	t_texture texture;

	if (!(texture.NO.ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.NO, &texture.NO.width, &texture.NO.height)))
		throw_error("North texture can't be opened");
	if (!(texture.SO.ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.SO, &texture.SO.width, &texture.SO.height)))
		throw_error("South texture can't be opened");
	if (!(texture.EA.ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.EA, &texture.EA.width, &texture.EA.height)))
		throw_error("East texture can't be opened");
	if (!(texture.WE.ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.WE, &texture.WE.width, &texture.WE.height)))
		throw_error("West texture can't be opened");
	texture.NO.data = (int*)mlx_get_data_addr(texture.NO.ptr, &texture.NO.bpp, &texture.NO.size_line, &texture.NO.endian);
	texture.SO.data = (int*)mlx_get_data_addr(texture.SO.ptr, &texture.SO.bpp, &texture.SO.size_line, &texture.SO.endian);
	texture.EA.data = (int*)mlx_get_data_addr(texture.EA.ptr, &texture.EA.bpp, &texture.EA.size_line, &texture.EA.endian);
	texture.WE.data = (int*)mlx_get_data_addr(texture.WE.ptr, &texture.WE.bpp, &texture.WE.size_line, &texture.WE.endian);
	return (texture);
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

static t_fps init_fps()
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
	//en->mlx.texture = init_texture(en);
}