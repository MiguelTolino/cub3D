/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 04:21:21 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/06 11:54:08 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "mlx.h"
#include "config/config.h"
#include <math.h>
#include "../includes/key_linux.h"

#define MOVE_SPEED 0.05
#define ROT_SPEED 0.05

typedef struct s_vector
{
	double x;
	double y;
} t_vector;

typedef struct s_mlx
{
	void *ptr;
	void *win;
	void *img;
	int bpp;
	int size_line;
	int endian;
	char *data;
} t_mlx;

typedef struct s_engine
{
	t_vector pos;
	t_vector dir;
	t_vector plane;
	t_vector camera;
	t_vector ray_dir;
	t_vector side_dist;
	t_vector delta_dist;
	double perp_wall_dist;
	int hit;
	int side;
	int draw_start;
	int draw_end;
	double time;
	double old_time;
	int map_x;
	int map_y;
	int step_x;
	int step_y;
	int line_height;
	int color;
	t_mlx mlx;
} t_engine;

int create_window(t_engine *en);
void init(t_engine *en);
int gameloop(t_engine *en);
void print_data(t_engine en);
int read_keys(int keycode, t_engine *en);
int rotate_player(t_engine *en, int dir);
void draw(t_engine *en, int x);
int get_color(t_engine *en);
int rgb_int(int r, int g, int b);

#endif
