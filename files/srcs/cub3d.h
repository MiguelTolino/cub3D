/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 04:21:21 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/09 14:29:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../includes/mlx.h"
#include "config/config.h"
#include <math.h>
#include "../includes/key_linux.h"
#include <time.h>

#define MOVE_SPEED 0.08
#define ROT_SPEED 0.05

typedef struct s_fps
{
	clock_t time;
	clock_t old_time;
	double counter;
	double max;
	double min;
	double average;
	double num;
} t_fps;

typedef struct s_vector
{
	double x;
	double y;
} t_vector;

typedef struct s_key_buff
{
	int up;
	int down;
	int left;
	int right;
	int rot_left;
	int rot_right;
	int esc;
	
}t_key_buff;

typedef struct s_mlx
{
	void *ptr;
	void *win;
	void *img;
	int bpp;
	int size_line;
	int endian;
	int *data;
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
	int map_x;
	int map_y;
	int step_x;
	int step_y;
	int line_height;
	int color;
	t_mlx mlx;
	t_key_buff k_buff;
	t_fps fps;
	double move_speed;
	double rot_speed;
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
int key_release(int keycode, t_engine *en);
int movement(t_engine *en);
int key_press(int keycode, t_engine *en);
void get_time(t_engine *en);
int exit_game(t_engine *en);
int raycasting(t_engine *en);


#endif
