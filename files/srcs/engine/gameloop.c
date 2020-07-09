/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:01:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/10 00:53:35 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int gameloop(t_engine *en)
{
	char *fps;
	
	movement(en);
	raycasting(en);
	fps = get_time(en);
	mlx_put_image_to_window(en->mlx.ptr, en->mlx.win, en->mlx.img.ptr, 0, 0);
	mlx_string_put(en->mlx.ptr, en->mlx.win, 20, 20, 0, fps);
 	usleep(10000);
//	free(fps);
//	system("clear"); */
	return (0);
}