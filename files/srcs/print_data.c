/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:34:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/26 12:10:12 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void print_data(t_cam cam)
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

	printf("Map:\n");
	i = 0;
	while (i < g_config.map.n_row)
	{
		printf("%s\n", g_config.map.world_map[i]);
		i++;
	}
	
	
}