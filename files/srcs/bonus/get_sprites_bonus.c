/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:30:22 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/14 19:44:58 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define UDIV 1
#define VDIV 1
#define VMOVE 128.0

static void			sort_sprites(t_engine *en)
{
	int				i;

	i = 0;
	while (i < en->num_sprites)
	{
		en->sprite_order[i] = i;
		en->sprite_distance[i] = ((en->pos.x - en->sprite[i].x) *
		(en->pos.x - en->sprite[i].x) + (en->pos.y - en->sprite[i].y) *
		(en->pos.y - en->sprite[i].y));
		i++;
	}
	sort_sprites_bubble(en);
}

static void			sprites_calculation(t_engine *en, t_sprite_cast *s, int i)
{
	s->sprite.x = en->sprite[en->sprite_order[i]].x - en->pos.x;
	s->sprite.y = en->sprite[en->sprite_order[i]].y - en->pos.y;
	s->inv_det = 1.0 / (en->plane.x * en->dir.y - en->dir.x * en->plane.y);
	s->transform.x = s->inv_det * (en->dir.y * s->sprite.x - en->dir.x * s->sprite.y);
	s->transform.y = s->inv_det * (-en->plane.y * s->sprite.x + en->plane.x * s->sprite.y);
	s->v_move_screen = (int)(VMOVE / s->transform.y);
	s->sprite_screen_x = (int)((g_config.R.x / 2) * (1 + s->transform.x / s->transform.y));
	s->sprite_height = abs((int)(g_config.R.y / (s->transform.y))) / VDIV;
	s->draw_start.y = -s->sprite_height / 2 + g_config.R.y / 2 + s->v_move_screen;
	if (s->draw_start.y < 0)
		s->draw_start.y = 0;
	s->draw_end.y = s->sprite_height / 2 + g_config.R.y / 2 + s->v_move_screen;
	if (s->draw_end.y >= g_config.R.y)
		s->draw_end.y = g_config.R.y - 1;
	s->sprite_width = abs((int)(g_config.R.y / (s->transform.y))) / UDIV;
	s->draw_start.x = -s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_start.x < 0)
		s->draw_start.x = 0;
	s->draw_end.x = s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_end.x >= g_config.R.x)
		s->draw_end.x = g_config.R.x - 1;
}

static void			put_sprite_to_image(t_engine *en, t_sprite_cast s, int stripe, int i)
{
	t_vector_int	tex;
	int				d;
	int				y;

	tex.x = (int)(256 * (stripe - (-s.sprite_width / 2 + s.sprite_screen_x)) * 64 / s.sprite_width) / 256;
	if (s.transform.y > 0 && stripe > 0 && stripe < g_config.R.x && s.transform.y < en->z_buff[stripe])
	{
		y = s.draw_start.y;
		while (y < s.draw_end.y)
		{
			d = (y - s.v_move_screen) * 256 - g_config.R.y * 128 + s.sprite_height * 128;
			tex.y = ((d * 64) / s.sprite_height) / 256;
			en->color = en->mlx.texture[6].data[64 * tex.y + tex.x];
			if (en->color != en->mlx.texture[6].data[0])
				*(en->mlx.img.data + (y * g_config.R.x) + stripe) = en->color;
			y++;
		}
	}
}

int				sprite_casting(t_engine *en)
{
	int				i;
	int				y;
	int				stripe;
	t_sprite_cast	s;

	i = 0;
	sort_sprites(en);
	while (i < en->num_sprites)
	{
		sprites_calculation(en, &s, i);
		stripe = s.draw_start.x;
		while (stripe < s.draw_end.x)
		{
			put_sprite_to_image(en, s, stripe, i);
			stripe++;
		}
		i++;
	}
	return (0);
}
