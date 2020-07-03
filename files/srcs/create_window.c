/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 18:25:58 by miguel            #+#    #+#             */
/*   Updated: 2020/07/03 14:02:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int create_window(t_engine *en)
{
	if(!((en->mlx.ptr = mlx_init())))
		throw_error("Failed minilibx connection");
	if(!(en->mlx.win = mlx_new_window(en->mlx.ptr, g_config.R.x, g_config.R.y, "cub3D")))
		throw_error("There was a problem with window creation");
	if (!(en->mlx.img = mlx_new_image(en->mlx.ptr, g_config.R.x, g_config.R.y)))
		throw_error("Image cannot be created");
	en->mlx.data = mlx_get_data_addr(en->mlx.img, &en->mlx.bpp, &en->mlx.size_line, &en->mlx.endian);
    return (1);
}