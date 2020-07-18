/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:42:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 14:06:05 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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

static t_fps		init_fps(void)
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

static void			init_sprites(t_engine *en)
{
	en->num_sprites = get_num_sprites();
	en->sprite = set_sprites(en->num_sprites);
	en->z_buff = malloc(sizeof(double) * g_config.r.x);
	en->sprite_order = malloc(sizeof(int) * en->num_sprites);
	en->sprite_distance = malloc(sizeof(double) * en->num_sprites);
}

void				init(t_engine *en)
{
	en->pos.x = g_config.pos_x + 0.5;
	en->pos.y = g_config.pos_y + 0.5;
	orientation(en);
	en->k_buff = init_key_buff();
	en->fps = init_fps();
	en->mlx.texture = init_texture(en);
	init_sprites(en);
}
