/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:17:18 by miguel            #+#    #+#             */
/*   Updated: 2020/06/12 19:07:44 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void check_resolution(t_resolution *R)
{
    if (R->x < MIN_WIDTH)
        R->x = MIN_WIDTH;
    if (R->y < MIN_HEIGHT)
        R->y = MIN_HEIGHT;
    if (R->x > MAX_WIDTH)
        R->x = MAX_WIDTH;
    if (R->y > MAX_HEIGHT)
        R->y = MAX_HEIGHT;
}

t_resolution save_resolution(char *line)
{
    char **aux;
    t_resolution R;

    aux = ft_split(line, ' ');
    check_len(aux, 3);
    if (is_digit(aux[1]) && is_digit(aux[2]))
    {
        R.x = ft_atoi(aux[1]);
        R.y = ft_atoi(aux[2]);
    }
    else
        throw_error("Error: Resolution is wrong, check and run it again");

    check_resolution(&R);
    free_str(aux);
    return (R);
}