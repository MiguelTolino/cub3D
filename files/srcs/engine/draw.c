/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:34:05 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/10 00:10:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw(t_engine *en, int x)
{
    int i;

    i = 0;
    while (i < en->draw_start)
    {
        *(en->mlx.img.data + (i * g_config.R.x) + x) = g_config.C.rgb_int;
        i++;
    }
    while (i < en->draw_end)
    {
        if (g_config.map.world_map[en->map_x][en->map_y] == '1')
        {
            en->tex.y = (int)en->tex.pos & (en->mlx.texture[en->tex.num].height - 1);
            en->tex.pos += en->tex.step;
            en->color = en->mlx.texture[en->tex.num].data[en->mlx.texture[en->tex.num].height * en->tex.y + en->tex.x];
            *(en->mlx.img.data + (i * g_config.R.x) + x) = en->color;
        }
        if (g_config.map.world_map[en->map_x][en->map_y] == '2')
            {
                en->color = 255;
                if (en->side == 1)
                    en->color = en->color / 2;
                *(en->mlx.img.data + (i * g_config.R.x) + x) = en->color;
            }

        i++;
    }
    while (i < g_config.R.y)
    {
        *(en->mlx.img.data + (i * g_config.R.x) + x) = g_config.F.rgb_int;
        i++;
    }
}
