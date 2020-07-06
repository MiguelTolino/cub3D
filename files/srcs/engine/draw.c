/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:34:05 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/06 11:35:02 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw(t_engine *en, int x)
{
	int i = en->draw_start;
	while (i <= en->draw_end)
		mlx_pixel_put(en->mlx.ptr, en->mlx.win, x, i++, en->color);
}