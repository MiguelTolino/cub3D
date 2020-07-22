/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:11:06 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/22 13:15:25 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static int	check_color_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!(ft_strchr("0123456789FC ,", line[i])))
			throw_error("Wrong colors");
		i++;
	}
	return (0);
}

char		*rgb2hex(int r, int g, int b)
{
	char	*hex;
	char	*rgb2hex;

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

int			rgb_int(int r, int g, int b)
{
	if (r > 255 || b > 255 || g > 255 || b < 0 || g < 0 || r < 0)
		throw_error("Error: RGB Color is wrong");
	return (65536 * r + 256 * g + b);
}

t_color		save_color(char *line, char *position)
{
	t_color	color;
	int		i;

	i = 0;
	line = position;
	check_color_line(line);
	while (i < 3)
	{
		line++;
		color.rgb[i] = ft_atoi(line);
		if ((((line = ft_strchr(line, ',')) == NULL) && (i != 2)) ||
		(line != NULL && i == 2))
			throw_error("Wrong colors");
		i++;
	}
	color.rgb_hex = rgb2hex(color.rgb[0], color.rgb[1], color.rgb[2]);
	color.rgb_int = rgb_int(color.rgb[0], color.rgb[1], color.rgb[2]);
	return (color);
}
