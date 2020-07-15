/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:37:19 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/15 18:14:19 by mmateo-t         ###   ########.fr       */
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
			if (g_config.map.world_map[i][j] == '2')
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
			if (g_config.map.world_map[i][j] == '2')
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

void			sort_sprites_bubble(t_engine *en)
{
	int		i;
	double	tmp;
	int		tmp2;

	i = 0;
	while (i < en->num_sprites - 1)
	{
		if (en->sprite_distance[i] < en->sprite_distance[i + 1])
		{
			tmp = en->sprite_distance[i + 1];
			en->sprite_distance[i + 1] = en->sprite_distance[i];
			en->sprite_distance[i] = tmp;
			tmp2 = en->sprite_order[i + 1];
			en->sprite_order[i + 1] = en->sprite_order[i];
			en->sprite_order[i] = tmp2;
			i = 0;
		}
		else
			i++;
	}
}
