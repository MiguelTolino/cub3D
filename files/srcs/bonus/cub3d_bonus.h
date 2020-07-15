/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 04:21:21 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/15 17:46:07 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../../includes/mlx.h"
#include "config/config_bonus.h"
#include <math.h>
#include "../../includes/key_linux.h"
#include <time.h>

#define MOVE_SPEED 0.08
#define ROT_SPEED 0.05

typedef struct s_bmp
{
	unsigned char type[2];
	int file_size;
	int reserved;
	int offset;
	unsigned int size_header;
	unsigned int width;
	unsigned int height;
	short int planes;
	short int bit_count;
	unsigned int compression;
	unsigned int image_size;
	unsigned int ppm_x;
	unsigned int ppm_y;
	unsigned int clr_used;
	unsigned int clr_important;
	int color;
	
} t_bmp;

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

typedef struct s_vector_int
{
	int x;
	int y;
} t_vector_int;

typedef struct s_key_buff
{
	int up;
	int down;
	int left;
	int right;
	int rot_left;
	int rot_right;
	int esc;

} t_key_buff;

typedef struct s_img
{
	int *data;
	void *ptr;
	int size_line;
	int endian;
	int bpp;
	int width;
	int height;

} t_img;

typedef struct s_mlx
{
	void *ptr;
	void *win;
	t_img img;
	t_img *texture;
	t_img sprite;
} t_mlx;

typedef struct s_tex
{
	int num;
	double wall_x;
	int x;
	int y;
	double step;
	double pos;

} t_tex;

typedef struct s_sprite
{
	double x;
	double y;
	int num;
} t_sprite;

typedef struct s_sprite_cast
{
	t_vector sprite;
	double inv_det;
	t_vector transform;
	int sprite_screen_x;
	int sprite_height;
	int sprite_width;
	t_vector_int draw_start;
	t_vector_int draw_end;
	int v_move_screen;
} t_sprite_cast;

typedef struct s_cf_tex
{
	t_vector ray_dir_0;
	t_vector ray_dir_1;
	t_vector floor_step;
	t_vector floor;
	t_vector cell;
	t_vector t;
	int p;
	float pos_z;
	float row_distance;
} t_cf_tex;

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
	t_tex tex;
	t_cf_tex cf;
	double move_speed;
	double rot_speed;
	double *z_buff;
	int num_sprites;
	t_sprite *sprite;
	int *sprite_order;
	double *sprite_distance;

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
char *get_time(t_engine *en);
int exit_game(t_engine *en);
int raycasting(t_engine *en);
int get_texture(t_engine *en);
void floor_casting(t_engine *en);
int floor_casting_2(t_engine *en, int x);
int get_num_sprites();
t_sprite *set_sprites(int num);
int sprite_casting(t_engine *en);
void sort_sprites_bubble(t_engine *en);
void sprite_test(t_engine *en);
void save_bmp(t_engine *en);

#endif
