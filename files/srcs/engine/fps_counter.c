/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 12:30:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/09 18:36:04 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_time(t_engine *en)
{
	double frame_time;

	en->fps.old_time = en->fps.time;
	en->fps.time = clock();
	frame_time = (double)(en->fps.time - en->fps.old_time) / CLOCKS_PER_SEC;
	en->fps.counter = (1.0 / frame_time);
	en->fps.average += en->fps.counter;
	en->fps.num++;
	if (en->fps.counter > en->fps.max)
		en->fps.max = en->fps.counter;
	if (en->fps.counter < en->fps.min)
		en->fps.min = en->fps.counter;

	en->move_speed = frame_time * 5;
	en->rot_speed = frame_time * 3;
	if (en->fps.counter < 100)
	{
		printf("MOVE SPEED: %f\t", en->move_speed);
		printf("ROT SPEED: %f\n", en->rot_speed);
		printf("FPS: %.2f\t\t\t", en->fps.counter);
		printf("Max: %.2f\t\t\t", en->fps.max);
		printf("Mean: %.2f\t\t\t", en->fps.average / en->fps.num);
		printf("Min: %.2f\n", en->fps.min);
	}
}
