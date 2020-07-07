/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 20:23:15 by miguel            #+#    #+#             */
/*   Updated: 2020/07/07 12:16:05 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void throw_error(const char *str)
{
	char *str2;
	
	str2 = ft_strjoin("Error\n", str);
    perror(str2);
	free(str2);
    exit(0);
}

int exit_game(t_engine *en)
{
	mlx_destroy_window(en->mlx.ptr, en->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}