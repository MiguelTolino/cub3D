/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:44:15 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/14 20:13:29 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_side(t_engine *en)
{
	int num;

	if (en->ray_dir.x < 0 && en->side == 0)
		num = 0;
	if (en->ray_dir.x > 0 && en->side == 0)
		num = 1;
	if (en->ray_dir.y < 0 && en->side == 1)
		num = 2;
	if (en->ray_dir.y > 0 && en->side == 1)
		num = 3;
	return (num);
}

int			get_texture(t_engine *en)
{
	en->tex.num = get_side(en);
	if (en->side == 0)
		en->tex.wall_x = en->pos.y + en->perp_wall_dist * en->ray_dir.y;
	else
		en->tex.wall_x = en->pos.x + en->perp_wall_dist * en->ray_dir.x;
	en->tex.wall_x -= floor(en->tex.wall_x);
	en->tex.x = (int)(en->tex.wall_x * (double)(en->mlx.texture[en->tex.num].width));
	if (en->side == 0 && en->ray_dir.x > 0)
		en->tex.x = en->mlx.texture[en->tex.num].width - en->tex.x - 1;
	if (en->side == 1 && en->ray_dir.y < 0)
		en->tex.x = en->mlx.texture[en->tex.num].width - en->tex.x - 1;
	en->tex.step = 1.0 * en->mlx.texture[en->tex.num].height / en->line_height;
	en->tex.pos = (en->draw_start - g_config.R.y / 2 + en->line_height / 2) * en->tex.step;
	return (0);
}

static void	fc_casting_calculate(t_engine *en, int y)
{
	en->cf.ray_dir_0.x = en->dir.x - en->plane.x;
	en->cf.ray_dir_0.y = en->dir.y - en->plane.y;
	en->cf.ray_dir_1.x = en->dir.x + en->plane.x;
	en->cf.ray_dir_1.y = en->dir.y + en->plane.y;
	en->cf.p = y - g_config.R.y / 2;
	en->cf.pos_z = 0.5 * g_config.R.y;
	en->cf.row_distance = en->cf.pos_z / en->cf.p;
	en->cf.floor_step.x = en->cf.row_distance * (en->cf.ray_dir_1.x - en->cf.ray_dir_0.x) / g_config.R.x;
	en->cf.floor_step.y = en->cf.row_distance * (en->cf.ray_dir_1.y - en->cf.ray_dir_0.y) / g_config.R.x;
	en->cf.floor.x = en->pos.x + en->cf.row_distance * en->cf.ray_dir_0.x;
	en->cf.floor.y = en->pos.y + en->cf.row_distance * en->cf.ray_dir_0.y;
}

void		floor_casting(t_engine *en)
{
	int x;
	int y;

	y = 0;
	while (y < g_config.R.y)
	{
		fc_casting_calculate(en, y);
		x = 0;
		while (x < g_config.R.x)
		{
			en->cf.cell.x = (int)(en->cf.floor.x);
			en->cf.cell.y = (int)(en->cf.floor.y);
			en->cf.t.x = (int)(en->mlx.texture[4].width * (en->cf.floor.x - en->cf.cell.x)) & (en->mlx.texture[4].width - 1);
			en->cf.t.y = (int)(en->mlx.texture[4].height * (en->cf.floor.y - en->cf.cell.y)) & (en->mlx.texture[4].height - 1);
			en->cf.floor.x += en->cf.floor_step.x;
			en->cf.floor.y += en->cf.floor_step.y;
			en->color = (int)en->mlx.texture[5].data[(int)(en->mlx.texture[5].width * en->cf.t.y + en->cf.t.x)];
			*(en->mlx.img.data + (y * g_config.R.x) + x) = en->color;
			en->color = (int)en->mlx.texture[4].data[(int)(en->mlx.texture[4].width * en->cf.t.y + en->cf.t.x)];
			*(en->mlx.img.data + ((g_config.R.y - y - 1) * g_config.R.x) + x) = en->color;
			x++;
		}
		y++;
	}
}
