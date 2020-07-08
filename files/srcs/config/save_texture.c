/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:27:38 by miguel            #+#    #+#             */
/*   Updated: 2020/07/08 11:32:00 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

//TODO Imágenes son reproducidas "on the fly". Si ese es el caso corregir funcion

char *save_texture(char *line)
{
	char *texture;
	int fd;
	char **num_str;
	char *filedir;
	char *aux;

	num_str = ft_split(line, ' ');
	check_len(num_str, 2);
	filedir = ft_strdup(num_str[1]);
	free_str(num_str);
	if(((fd = open(filedir, O_RDONLY)) < 0))
		throw_error("FD_TEXTURE can't be opened");
	free(filedir);
	texture = ft_strdup("");
	while (get_next_line(fd, &filedir) > 0)
	{
		aux = ft_strjoin(texture, filedir);
		free(texture);
		texture = aux;
	}
	free(filedir);
	close(fd);
	g_config.counter++;
	return(texture);
}