/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:02:25 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/07 20:37:52 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
  t_engine en;
  check_arg(argc, argv);
  read_config(argv[1]);
  
  init(&en);
  print_data(en);
  create_window(&en);
  gameloop(&en);
  mlx_do_key_autorepeatoff(en.mlx.ptr);
	mlx_hook(en.mlx.win, 2, 1, key_press, &en);
	mlx_hook(en.mlx.win, 3, 2, key_release, &en);
  mlx_loop_hook(en.mlx.ptr, move_draw, &en);
	mlx_hook(en.mlx.win, 17, 1L << 17, exit_game, &en);
  mlx_loop(en.mlx.ptr);
  return (0);
}
