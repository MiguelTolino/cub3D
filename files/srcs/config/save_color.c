/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 21:05:22 by miguel            #+#    #+#             */
/*   Updated: 2020/04/05 21:07:41 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

char *rgb2hex(int r, int g, int b)
{
	char *hex;
	char *rgb2hex;

	hex = "0123456789abcdef";
	if (!(rgb2hex = malloc(sizeof(char) * 8)))
	{
		return (NULL);
	}
	if (r > 255 || b > 255 || g > 255 || b < 0 || g < 0 || r < 0)
	{
		throw_error("Error: RGB Color is wrong");
	}
	rgb2hex[0] = '#';
	rgb2hex[1] = hex[r / 16];
	rgb2hex[2] = hex[r % 16];
	rgb2hex[3] = hex[g / 16];
	rgb2hex[4] = hex[g % 16];
	rgb2hex[5] = hex[b / 16];
	rgb2hex[6] = hex[b % 16];
	rgb2hex[7] = '\0';

	return (rgb2hex);
}

int rgb_int(int r, int g, int b)
{
	if (r > 255 || b > 255 || g > 255 || b < 0 || g < 0 || r < 0)
		throw_error("Error: RGB Color is wrong");
	return (65536 * r + 256 * g + b);
}

t_color save_color(char *line, char *position)
{
	t_color color;
	int i;

	i = 0;
	line = position;
	while (i < 3)
	{
		line++;
		color.rgb[i] = ft_atoi(line);
		line = ft_strchr(line, ',');
		if (line != NULL && i == 2)
			throw_error("Too many colors");
		i++;
	}
	color.rgb_hex = rgb2hex(color.rgb[0], color.rgb[1], color.rgb[2]);
	color.rgb_int = rgb_int(color.rgb[0], color.rgb[1], color.rgb[2]);
	g_config.counter++;
	return (color);
}