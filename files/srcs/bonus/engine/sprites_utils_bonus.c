/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:37:19 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/17 01:30:43 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int				get_num_sprites(void)
{
	int i;
	int j;
	int num;

	i = 0;
	num = 0;
	while (i < g_config.map.n_row)
	{
		j = 0;
		while (j < g_config.map.n_col)
		{
			if (g_config.map.world_map[i][j] == '2' || g_config.map.world_map[i][j] == '5')
			{
				num++;
			}
			j++;
		}
		i++;
	}
	return (num);
}

t_sprite		*set_sprites(int num)
{
	t_sprite	*sprites;
	int			i;
	int			j;
	int			cont;

	i = 0;
	cont = 0;
	sprites = malloc(sizeof(t_sprite) * num);
	while (i < g_config.map.n_row)
	{
		j = 0;
		while (j < g_config.map.n_col)
		{
			if (g_config.map.world_map[i][j] == '2' ||  g_config.map.world_map[i][j] == '5')
			{
				sprites[cont].num = g_config.map.world_map[i][j] - '0';
				sprites[cont].x = i + 0.6;
				sprites[cont].y = j + 0.6;
				cont++;
			}
			j++;
		}
		i++;
	}
	return (sprites);
}

void	sort_sprites_bubble(t_engine *en)
{
	int			i;
	double		dist_swap;
	t_sprite	s;

	i = 1;
	while (i < en->num_sprites)
	{
		if (en->sprite_distance[i - 1] < en->sprite_distance[i])
		{
			dist_swap = en->sprite_distance[i - 1];
			en->sprite_distance[i - 1] = en->sprite_distance[i];
			en->sprite_distance[i] = dist_swap;
			s = en->sprite[i - 1];
			en->sprite[i - 1] = en->sprite[i];
			en->sprite[i] = s;
			i = 1;
		}
		else
			i++;
	}
}