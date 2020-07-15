/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_attributes_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 00:44:15 by miguel            #+#    #+#             */
/*   Updated: 2020/07/15 18:16:38 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_bonus.h"

int		check_arg(int argc, char **argv)
{
	g_config.save = 0;
	if (argc > 3 || argc <= 1)
		throw_error("The number of main arguments are wrong");
	if (!(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))
	&& ft_strlen(argv[1]) > 4))
		throw_error("Argument does not have the extension .cub");
	if (argc == 3)
	{
		if ((ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0))
			throw_error("Option couldn't be recognized");
		else
			g_config.save = 1;
	}
	return (1);
}
