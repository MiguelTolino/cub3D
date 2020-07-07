/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:02:25 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/07 12:38:19 by mmateo-t         ###   ########.fr       */
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
	//mlx_key_hook(en.mlx.win, key_release, &en);
  mlx_key_hook(en.mlx.win, read_keys, &en);
  mlx_loop_hook(en.mlx.ptr, gameloop, &en);
  mlx_loop(en.mlx.ptr);
  return (0);
}
