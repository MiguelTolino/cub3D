/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 20:23:15 by miguel            #+#    #+#             */
/*   Updated: 2020/07/09 14:29:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void throw_error(const char *str)
{
	char *str2;
	
	str2 = ft_strjoin("Error\n", str);
    perror(str2);
	free(str2);
    exit(EXIT_FAILURE);
}

int exit_game(t_engine *en)
{
	mlx_destroy_window(en->mlx.ptr, en->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}