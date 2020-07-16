/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:34:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/16 20:05:39 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void print_data(t_engine en)
{
	int i;

	i = 0;
	printf("Resolution:\n");
	printf("Width: %i\n", g_config.R.x);
	printf("Height: %i\n", g_config.R.y);
	printf("Floor rgb_hex: %s\n", g_config.F.rgb_hex);
	while (i < 3)
	{
		printf("Floor rgb[%i]: %i\n", i, g_config.F.rgb[i]);
		i++;
	}
	i = 0;
	printf("Ceiling rgb_hex: %s\n", g_config.C.rgb_hex);
	while (i < 3)
	{
		printf("Ceiling rgb[%i]: %i\n", i, g_config.C.rgb[i]);
		i++;
	}

	//TEXTURES

	printf("NO: %s\n", g_config.NO);
	printf("SO: %s\n", g_config.SO);
	printf("EA: %s\n", g_config.EA);
	printf("WE: %s\n", g_config.WE);
	printf("S: %s\n", g_config.S);
	printf("CT: %s\n", g_config.CT);
	printf("FT: %s\n", g_config.FT);
	printf("TX1: %s\n", g_config.TX1);
	printf("TX2: %s\n", g_config.TX2);

	printf("PosX: %i\n", g_config.pos_x);
	printf("PosY: %i\n", g_config.pos_y);
	//printf("Orientacion: %c\n", g_config.map.world_map[g_config.pos_x][g_config.pos_y]);
	printf("Map:\n");
	i = 0;
	while (i < g_config.map.n_row)
	{
		printf("%s\n", g_config.map.world_map[i]);
		i++;
	}
	printf("Position X: %f\n", en.pos.x);
	printf("Position Y: %f\n", en.pos.y);

	i = 0;
	while (i < en.num_sprites)
	{
		printf("Nº%i \t Distance: %f \t Num: %i\n", i, en.sprite_distance[i], en.sprite_order[i]);
		i++;
	}
}