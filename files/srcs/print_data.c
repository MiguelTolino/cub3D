/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:34:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/09 18:03:42 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		printf("Floor rgb[%i]: %i\n", i , g_config.F.rgb[i]);
		i++;
	}
	i = 0;
	printf("Ceiling rgb_hex: %s\n", g_config.C.rgb_hex);
	while (i < 3)
	{
		printf("Ceiling rgb[%i]: %i\n", i , g_config.C.rgb[i]);
		i++;
	}

	//TEXTURES
	
	printf("NO: %s\n", g_config.NO);
	printf("SO: %s\n", g_config.SO);
	printf("EA: %s\n", g_config.EA);
	printf("WE: %s\n", g_config.WE);
	printf("S: %s\n", g_config.S);

	printf("PosX: %i\n", g_config.pos_x);
	printf("PosY: %i\n", g_config.pos_y);
	printf("Orientacion: %c\n", g_config.map.world_map[g_config.pos_x][g_config.pos_y]);
	printf("Map:\n");
	i = 0;
	while (i < g_config.map.n_row)
	{
		printf("%s\n", g_config.map.world_map[i]);
		i++;
	}
	 printf("Position X: %f\n", en.pos.x); 
	 printf("Position Y: %f\n", en.pos.y);

	 //Direction
	 printf("DirX: %f\n",en.dir.x);
	 printf("DirY: %f\n",en.dir.y);
}