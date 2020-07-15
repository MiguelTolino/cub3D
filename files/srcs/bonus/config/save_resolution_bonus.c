/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_resolution_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:17:18 by miguel            #+#    #+#             */
/*   Updated: 2020/07/15 18:16:38 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_bonus.h"

static void		check_resolution(t_resolution *r)
{
	if (r->x < MIN_WIDTH)
		r->x = MIN_WIDTH;
	if (r->y < MIN_HEIGHT)
		r->y = MIN_HEIGHT;
	if (r->x > MAX_WIDTH)
		r->x = MAX_WIDTH;
	if (r->y > MAX_HEIGHT)
		r->y = MAX_HEIGHT;
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
	g_config.counter++;
	return (r);
}
