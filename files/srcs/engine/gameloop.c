/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:01:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/15 14:16:56 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		destroy_create_image(t_engine *en)
{
	mlx_destroy_image(en->mlx.ptr, en->mlx.img.ptr);
	en->mlx.img.ptr = mlx_new_image(en->mlx.ptr, g_config.R.x, g_config.R.y);
	en->mlx.img.data = (int*)mlx_get_data_addr(en->mlx.img.ptr,
	&en->mlx.img.bpp, &en->mlx.img.endian, &en->mlx.img.size_line);
}

int				gameloop(t_engine *en)
{
	movement(en);
	raycasting(en);
	sprite_casting(en);
	mlx_put_image_to_window(en->mlx.ptr, en->mlx.win, en->mlx.img.ptr, 0, 0);
	if (g_config.save)
	{
		save_bmp(en);
		exit_game(en);
	}
	destroy_create_image(en);
	return (0);
}
