/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:01:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/21 23:45:32 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void		put_images(t_engine *en)
{
	mlx_put_image_to_window(en->mlx.ptr, en->mlx.win, en->mlx.img.ptr, 0, 0);
	mlx_put_image_to_window(en->mlx.ptr, en->mlx.win, en->mlx.texture[10].ptr,
	g_config.r.x / 2 - 500, g_config.r.y / 2 - 500);
	mlx_put_image_to_window(en->mlx.ptr, en->mlx.win, en->mlx.texture[11].ptr,
	0, 0);
}

void			destroy_create_image(t_engine *en)
{
	mlx_destroy_image(en->mlx.ptr, en->mlx.img.ptr);
	en->mlx.img.ptr = mlx_new_image(en->mlx.ptr, g_config.r.x, g_config.r.y);
	en->mlx.img.data = (int*)mlx_get_data_addr(en->mlx.img.ptr,
	&en->mlx.img.bpp, &en->mlx.img.endian, &en->mlx.img.size_line);
}

int				gameloop(t_engine *en)
{
	char *fps;

	movement(en);
	floor_casting(en);
	draw_skybox(en);
	raycasting(en);
	sprite_casting(en);
	fps = get_time(en);
	put_images(en);
	if (g_config.save)
	{
		save_bmp(en);
		exit_game(en);
	}
	destroy_create_image(en);
	free(fps);
	return (0);
}
