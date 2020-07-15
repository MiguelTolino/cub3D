/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:27:38 by miguel            #+#    #+#             */
/*   Updated: 2020/07/15 13:22:13 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

char		*save_texture(char *line)
{
	char	**num_str;
	char	*filename;

	num_str = ft_split(line, ' ');
	check_len(num_str, 2);
	filename = ft_strdup(num_str[1]);
	free_str(num_str);
	g_config.counter++;
	return (filename);
}
