/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:11:16 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/20 17:58:43 by mmateo-t         ###   ########.fr       */
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
	return (filename);
}
