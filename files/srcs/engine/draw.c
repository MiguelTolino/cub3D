/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:34:05 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/06 19:43:03 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* void draw(t_engine *en, int x)
{
	int i;

	i = 0;
	while (i < en->draw_start)
	{
		*(en->mlx.data + (i * g_config.R.x) + x) = 255;
		i++;
	}
    while (i < en->draw_end)
    {
        *(en->mlx.data + (i * g_config.R.x) + x) = en->color;
        i++;
    }
    while (i < g_config.R.y)
    {
        *(en->mlx.data + (i * g_config.R.x) + x) = rgb_int(255,0,0);
		i++;
    }
} */

void draw(t_engine *en, int x)
{
	int i;

	i = en->draw_start;
    while (i < en->draw_end)
    {
        mlx_pixel_put(en->mlx.ptr, en->mlx.win, x, i, en->color);
        i++;
    }
}