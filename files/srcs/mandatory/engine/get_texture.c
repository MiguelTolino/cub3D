/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:42:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 02:39:23 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_side(t_engine *en)
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

int			get_texture(t_engine *en)
{
	en->tex.num = get_side(en);
	if (en->side == 0)
		en->tex.wall_x = en->pos.y + en->perp_wall_dist * en->ray_dir.y;
	else
		en->tex.wall_x = en->pos.x + en->perp_wall_dist * en->ray_dir.x;
	en->tex.wall_x -= floor(en->tex.wall_x);
	en->tex.x = (int)(en->tex.wall_x * (double)
	(en->mlx.texture[en->tex.num].width));
	if (en->side == 0 && en->ray_dir.x > 0)
		en->tex.x = en->mlx.texture[en->tex.num].width - en->tex.x - 1;
	if (en->side == 1 && en->ray_dir.y < 0)
		en->tex.x = en->mlx.texture[en->tex.num].width - en->tex.x - 1;
	en->tex.step = 1.0 * en->mlx.texture[en->tex.num].height / en->line_height;
	en->tex.pos = (en->draw_start - g_config.r.y / 2 + en->line_height / 2) *
	en->tex.step;
	return (0);
}
