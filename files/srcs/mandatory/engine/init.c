/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:44:39 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 02:40:27 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_img			*init_texture(t_engine *en)
{
	t_img			*texture;

	texture = malloc(sizeof(t_img) * 5);
	bzero(texture, sizeof(t_img));
	if (!(texture[0].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.no,
		&texture[0].width, &texture[0].height)))
		throw_error("North texture can't be opened");
	if (!(texture[1].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.so,
		&texture[1].width, &texture[1].height)))
		throw_error("South texture can't be opened");
	if (!(texture[2].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.ea,
		&texture[2].width, &texture[2].height)))
		throw_error("East texture can't be opened");
	if (!(texture[3].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.we,
		&texture[3].width, &texture[3].height)))
		throw_error("West texture can't be opened");
	if (!(texture[4].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.s,
		&texture[4].width, &texture[4].height)))
		throw_error("Sprite texture can't be opened");
	return (texture);
}

static t_key_buff		init_key_buff(void)
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

static void				init_sprites(t_engine *en)
{
	en->num_sprites = get_num_sprites();
	en->sprite = set_sprites(en->num_sprites);
	en->z_buff = malloc(sizeof(double) * g_config.r.x);
	en->sprite_order = malloc(sizeof(int) * en->num_sprites);
	en->sprite_distance = malloc(sizeof(double) * en->num_sprites);
}

void					init(t_engine *en)
{
	en->pos.x = g_config.pos_x + 0.5;
	en->pos.y = g_config.pos_y + 0.5;
	orientation(en);
	en->k_buff = init_key_buff();
	en->mlx.texture = init_texture(en);
	open_textures(en);
	init_sprites(en);
}
