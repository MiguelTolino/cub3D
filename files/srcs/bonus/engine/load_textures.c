/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:46:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/22 19:21:25 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#define HAND "./files/images/horror/hand1.xpm"
#define HEALTH "./files/images/textures/health.xpm"
#define SKYBOX "./files/images/comun/luna.xpm"

void			load_textures(t_img *texture)
{
	texture[0].data = (int*)mlx_get_data_addr(texture[0].ptr,
	&texture[0].bpp, &texture[0].size_line, &texture[0].endian);
	texture[1].data = (int*)mlx_get_data_addr(texture[1].ptr,
	&texture[1].bpp, &texture[1].size_line, &texture[1].endian);
	texture[2].data = (int*)mlx_get_data_addr(texture[2].ptr,
	&texture[2].bpp, &texture[2].size_line, &texture[2].endian);
	texture[3].data = (int*)mlx_get_data_addr(texture[3].ptr,
	&texture[3].bpp, &texture[3].size_line, &texture[3].endian);
	texture[4].data = (int*)mlx_get_data_addr(texture[4].ptr,
	&texture[4].bpp, &texture[4].size_line, &texture[4].endian);
	texture[5].data = (int*)mlx_get_data_addr(texture[5].ptr,
	&texture[5].bpp, &texture[5].size_line, &texture[5].endian);
	texture[6].data = (int*)mlx_get_data_addr(texture[6].ptr,
	&texture[6].bpp, &texture[6].size_line, &texture[6].endian);
	texture[7].data = (int*)mlx_get_data_addr(texture[7].ptr,
	&texture[7].bpp, &texture[7].size_line, &texture[7].endian);
	texture[8].data = (int*)mlx_get_data_addr(texture[8].ptr,
	&texture[8].bpp, &texture[8].size_line, &texture[8].endian);
	texture[9].data = (int*)mlx_get_data_addr(texture[9].ptr,
	&texture[9].bpp, &texture[9].size_line, &texture[9].endian);
	texture[13].data = (int*)mlx_get_data_addr(texture[13].ptr,
	&texture[13].bpp, &texture[13].size_line, &texture[13].endian);
}

static void		more_textures2(t_engine *en, t_img *texture)
{
	if (!(texture[8].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.tx2,
		&texture[8].width, &texture[8].height)))
		throw_error("TX2 texture can't be opened");
	if (!(texture[9].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.s2,
		&texture[9].width, &texture[9].height)))
		throw_error("Sprite texture can't be opened");
	if (!(texture[10].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, HAND,
		&texture[10].width, &texture[10].height)))
		throw_error("Hand can't be opened");
	if (!(texture[11].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, HEALTH,
		&texture[11].width, &texture[11].height)))
		throw_error("Life bar can't be opened");
	if (!(texture[13].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, SKYBOX,
		&texture[13].width, &texture[13].height)))
		throw_error("Skybox can't be opened");
}

static void		more_textures1(t_engine *en, t_img *texture)
{
	if (!(texture[4].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.ct,
		&texture[4].width, &texture[4].height)))
		throw_error("Ceiling texture can't be opened");
	if (!(texture[5].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.ft,
		&texture[5].width, &texture[5].height)))
		throw_error("Floor texture can't be opened");
	if (!(texture[6].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.s1,
		&texture[6].width, &texture[6].height)))
		throw_error("Sprite texture can't be opened");
	if (!(texture[7].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.tx1,
		&texture[7].width, &texture[7].height)))
		throw_error("TX1 texture can't be opened");
	more_textures2(en, texture);
}

t_img			*init_texture(t_engine *en)
{
	t_img		*texture;

	texture = malloc(sizeof(t_img) * 14);
	bzero(texture, sizeof(t_img));
	if (!(texture[0].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.no,
		&texture[0].width, &texture[0].height)))
		throw_error("North texture can't be opened");
	if (!(texture[1].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.so,
		&texture[1].width, &texture[1].height)))
		throw_error("South texture can't be opened");
	if (!(texture[2].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.ea,
		&texture[2].width, &texture[2].height)))
		throw_error("East texture can't be opened");
	if (!(texture[3].ptr =
		mlx_xpm_file_to_image(en->mlx.ptr, g_config.we,
		&texture[3].width, &texture[3].height)))
		throw_error("West texture can't be opened");
	more_textures1(en, texture);
	load_textures(texture);
	return (texture);
}
