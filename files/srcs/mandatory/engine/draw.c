/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:38:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 02:40:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw(t_engine *en, int x)
{
	int i;

	i = 0;
	while (i < en->draw_start)
	{
		*(en->mlx.img.data + (i * g_config.r.x) + x) = g_config.c.rgb_int;
		i++;
	}
	while (i < en->draw_end)
	{
		en->tex.y = (int)en->tex.pos &
		(en->mlx.texture[en->tex.num].height - 1);
		en->tex.pos += en->tex.step;
		en->color = en->mlx.texture[en->tex.num].data[en->mlx.texture
		[en->tex.num].height * en->tex.y + en->tex.x];
		*(en->mlx.img.data + (i * g_config.r.x) + x) = en->color;
		i++;
	}
	while (i < g_config.r.y - 1)
	{
		*(en->mlx.img.data + (i * g_config.r.x) + x) = g_config.f.rgb_int;
		i++;
	}
}
