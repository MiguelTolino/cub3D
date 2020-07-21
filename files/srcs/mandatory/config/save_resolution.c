/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:11:11 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/21 15:03:02 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void		check_resolution(t_resolution *r)
{
	if (r->x < MIN_WIDTH || r->y < MIN_HEIGHT || r->x > MAX_WIDTH
	|| r->y > MAX_HEIGHT)
		throw_error("Resolution is wrong");
}

t_resolution	save_resolution(char *line)
{
	char			**aux;
	t_resolution	r;

	aux = ft_split(line, ' ');
	check_len(aux, 3);
	if (is_digit(aux[1]) && is_digit(aux[2]))
	{
		r.x = ft_atoi(aux[1]);
		r.y = ft_atoi(aux[2]);
	}
	else
		throw_error("Error: resolution is wrong, check and run it again");
	check_resolution(&r);
	free_str(aux);
	return (r);
}
