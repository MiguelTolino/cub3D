/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:01:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/09 14:29:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int gameloop(t_engine *en)
{
	movement(en);
	raycasting(en);
	get_time(en);
	mlx_put_image_to_window(en->mlx.ptr, en->mlx.win, en->mlx.img, 0, 0);
	usleep(10000);
	return (0);
}