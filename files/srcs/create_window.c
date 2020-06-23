/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 18:25:58 by miguel            #+#    #+#             */
/*   Updated: 2020/06/19 11:05:25 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int create_window(t_mlx *mlx)
{
	if(!((mlx->ptr = mlx_init())))
		throw_error("Failed minilibx connection");
	if(!(mlx->win = mlx_new_window(mlx->ptr, g_config.R.x, g_config.R.y, "cub3D")))
		throw_error("There was a problem with window creation");
    return (1);
}