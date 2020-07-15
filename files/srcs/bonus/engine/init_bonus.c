/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:42:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/15 18:14:19 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	orientation(t_engine *en)
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

static t_img	*init_texture(t_engine *en)
{
	t_img		*texture;

	//FIXME We create a pointer that should be free later. Think about any other solution
	texture = malloc(sizeof(t_img) * 7);
	bzero(texture, sizeof(t_img));
	if (!(texture[0].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.NO, &texture[0].width, &texture[0].height)))
		throw_error("North texture can't be opened");
	if (!(texture[1].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.SO, &texture[1].width, &texture[1].height)))
		throw_error("South texture can't be opened");
	if (!(texture[2].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.EA, &texture[2].width, &texture[2].height)))
		throw_error("East texture can't be opened");
	if (!(texture[3].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.WE, &texture[3].width, &texture[3].height)))
		throw_error("West texture can't be opened");
	if (!(texture[4].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.CT, &texture[4].width, &texture[4].height)))
		throw_error("Ceiling texture can't be opened");
	if (!(texture[5].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.FT, &texture[5].width, &texture[5].height)))
		throw_error("Floor texture can't be opened");
	if (!(texture[6].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.S, &texture[6].width, &texture[6].height)))
		throw_error("Sprite texture can't be opened");
	texture[0].data = (int*)mlx_get_data_addr(texture[0].ptr, &texture[0].bpp, &texture[0].size_line, &texture[0].endian);
	texture[1].data = (int*)mlx_get_data_addr(texture[1].ptr, &texture[1].bpp, &texture[1].size_line, &texture[1].endian);
	texture[2].data = (int*)mlx_get_data_addr(texture[2].ptr, &texture[2].bpp, &texture[2].size_line, &texture[2].endian);
	texture[3].data = (int*)mlx_get_data_addr(texture[3].ptr, &texture[3].bpp, &texture[3].size_line, &texture[3].endian);
	texture[4].data = (int*)mlx_get_data_addr(texture[4].ptr, &texture[4].bpp, &texture[4].size_line, &texture[4].endian);
	texture[5].data = (int*)mlx_get_data_addr(texture[5].ptr, &texture[5].bpp, &texture[5].size_line, &texture[5].endian);
	texture[6].data = (int*)mlx_get_data_addr(texture[6].ptr, &texture[6].bpp, &texture[6].size_line, &texture[6].endian);
	return (texture);
}

static t_key_buff	init_key_buff(void)
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

static t_fps	init_fps(void)
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

static void init_sprites(t_engine *en)
{
	en->num_sprites = get_num_sprites();
	en->sprite = set_sprites(en->num_sprites);
	en->z_buff = malloc(sizeof(double) * g_config.R.x);
	en->sprite_order = malloc(sizeof(int) * en->num_sprites);
	en->sprite_distance = malloc(sizeof(double) * en->num_sprites);
}

void init(t_engine *en)
{
	en->pos.x = g_config.pos_x + 0.5;
	en->pos.y = g_config.pos_y + 0.5;
	orientation(en);
	en->k_buff = init_key_buff();
	en->fps = init_fps();
	en->mlx.texture = init_texture(en);
	init_sprites(en);
}
