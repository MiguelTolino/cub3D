/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:18:16 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 13:11:10 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void		throw_error(const char *str)
{
	char	*str2;

	str2 = ft_strjoin("Error\n", str);
	perror(str2);
	free(str2);
	exit(EXIT_FAILURE);
}

int			exit_game(t_engine *en)
{
	mlx_destroy_window(en->mlx.ptr, en->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}
