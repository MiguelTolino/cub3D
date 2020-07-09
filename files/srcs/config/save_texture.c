/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:27:38 by miguel            #+#    #+#             */
/*   Updated: 2020/07/09 17:59:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

//TODO Imágenes son reproducidas "on the fly". Si ese es el caso corregir funcion

char		*save_texture(char *line)
{
	char	**num_str;
	char	*filename;
	char	*aux;

	num_str = ft_split(line, ' ');
	check_len(num_str, 2);
	filename = ft_strdup(num_str[1]);
	free_str(num_str);
	g_config.counter++;
	return (filename);
}
