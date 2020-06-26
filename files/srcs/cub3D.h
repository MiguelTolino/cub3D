/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 04:21:21 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/26 11:36:00 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "mlx.h"
#include "config/config.h"
#include <math.h>
#include "../includes/key_linux.h"

#define PLAYER_HEIGHT 32
#define FOV 60
#define GRID_SIZE 64

typedef struct s_vector
{
	double x;
	double y;
} t_vector;

typedef struct s_cam
{
	t_vector pos;
	t_vector dir;
	t_vector plane;
} t_cam;

typedef struct s_game
{
	t_vector pos;
	t_vector dir;
	t_vector plane;
	t_vector camera;
	t_vector ray_dir;
	t_vector side_dist;
	t_vector delta_dist;
	double perp_wall_dist;
	t_vector step;
	int hit;
	int side;
	int draw_start;
	int draw_end;
	double time;
	double old_time;
} t_game;


typedef struct s_mlx
{
	void *ptr;
	void *win;
	void *img;
} t_mlx;

int create_window(t_mlx *mlx);
t_cam init();
int gameloop(t_mlx *mlx, t_game player);
void print_data(t_cam cam);

#endif
