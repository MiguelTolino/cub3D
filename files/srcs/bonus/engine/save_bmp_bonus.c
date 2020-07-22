/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:34:09 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/22 13:33:15 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "sys/stat.h"
#define DPI 100
#define BMP_HEADER_SIZE 54

static t_bmp	init_bmp()
{
	t_bmp	bmp;
	int		ppm;

	ppm = 40 * DPI;
	bmp.type[0] = 'B';
	bmp.type[1] = 'M';
	bmp.file_size = (4 + 54) * g_config.r.x * g_config.r.y;
	bmp.reserved = 0;
	bmp.offset = 14;
	bmp.size_header = 40;
	bmp.width = g_config.r.x;
	bmp.height = g_config.r.y;
	bmp.planes = 1;
	bmp.bit_count = 32;
	bmp.compression = 0;
	bmp.image_size = bmp.file_size;
	bmp.ppm_x = ppm;
	bmp.ppm_y = ppm;
	bmp.clr_used = 0;
	bmp.clr_important = 0;
	return (bmp);
}

static void		write_bmp(int fd, t_bmp bmp)
{
	write(fd, &bmp.type, sizeof(bmp.type));
	write(fd, &bmp.file_size, sizeof(bmp.file_size));
	write(fd, &bmp.reserved, sizeof(bmp.reserved));
	write(fd, &bmp.offset, sizeof(bmp.offset));
	write(fd, &bmp.size_header, sizeof(bmp.size_header));
	write(fd, &bmp.width, sizeof(bmp.width));
	write(fd, &bmp.height, sizeof(bmp.height));
	write(fd, &bmp.planes, sizeof(bmp.planes));
	write(fd, &bmp.bit_count, sizeof(bmp.bit_count));
	write(fd, &bmp.compression, sizeof(bmp.compression));
	write(fd, &bmp.file_size, sizeof(bmp.file_size));
	write(fd, &bmp.ppm_x, sizeof(bmp.ppm_x));
	write(fd, &bmp.ppm_y, sizeof(bmp.ppm_y));
	write(fd, &bmp.clr_used, sizeof(bmp.clr_used));
	write(fd, &bmp.clr_important, sizeof(bmp.clr_important));
}

void			save_bmp(t_engine *en)
{
	int		fd;
	int		x;
	int		y;
	t_bmp	bmp;
	int		color;

	if (!(fd = open("cub3D.bmp", O_WRONLY | O_CREAT, S_IRWXU |
	O_TRUNC | O_APPEND)))
		throw_error("BMP Failed. Not created");
	bmp = init_bmp();
	write_bmp(fd, bmp);
	y = 0;
	while (y < g_config.r.y)
	{
		x = 0;
		while (x < g_config.r.x)
		{
			color = *(en->mlx.img.data + (g_config.r.y - y - 1) *
			g_config.r.x + x);
			write(fd, &color, 4);
			x++;
		}
		y++;
	}
	close(fd);
}
