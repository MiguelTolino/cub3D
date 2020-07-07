/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:34:05 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/07 20:42:22 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw(t_engine *en, int x)
{
	int i;

	i = 0;
	while (i < en->draw_start)
	{
		*(en->mlx.data + (i * g_config.R.x) + x) = g_config.C.rgb_int;
		i++;
	}
    while (i < en->draw_end)
    {
        *(en->mlx.data + (i * g_config.R.x) + x) = en->color;
        i++;
    }
    while (i < g_config.R.y)
    {
        *(en->mlx.data + (i * g_config.R.x) + x) = g_config.F.rgb_int;
		i++;
    }
}

int move_draw(t_engine *en)
{
	movement(en);
	gameloop(en);
	mlx_put_image_to_window(en->mlx.ptr, en->mlx.win, en->mlx.img, 0, 0);
	usleep(10000);
	return (0);
}