/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:34:05 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/19 02:29:01 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#define DARKNESS 2

int				dark_color(double distance, int color)
{
	t_color		c;
	double		dark;
	int			r;
	int			g;
	int			b;

	dark = (DARKNESS / distance);
	if (!dark)
		dark = 1;
	c.rgb[0] = (color >> 16) & 255;
	c.rgb[1] = (color >> 8) & 255;
	c.rgb[2] = color & 255;
	r = (int)(c.rgb[0] * dark);
	g = (int)(c.rgb[1] * dark);
	b = (int)(c.rgb[2] * dark);
	if (r > c.rgb[0])
		r = c.rgb[0];
	if (g > c.rgb[1])
		g = c.rgb[1];
	if (b > c.rgb[2])
		b = c.rgb[2];
	c.rgb_int = rgb_int((int)r, (int)g, (int)(b));
	return (c.rgb_int);
}

void			draw(t_engine *en, int x)
{
	int i;

	i = en->draw_start;
	while (i < en->draw_end)
	{
		en->tex.y = (int)en->tex.pos &
		(en->mlx.texture[en->tex.num].height - 1);
		en->tex.pos += en->tex.step;
		en->color = en->mlx.texture[en->tex.num].data
		[en->mlx.texture[en->tex.num].height
		* en->tex.y + en->tex.x];
		en->color = dark_color(en->perp_wall_dist, en->color);
		*(en->mlx.img.data + (i * g_config.r.x) + x) = en->color;
		i++;
	}
}
