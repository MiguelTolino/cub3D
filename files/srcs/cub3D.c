/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:02:25 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/06 19:43:32 by mmateo-t         ###   ########.fr       */
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
  //mlx_do_key_autorepeatoff(en.mlx.ptr);
  //mlx_hook(en.mlx.win, 2, 1, read_keys, &en);
	//mlx_key_hook(en.mlx.win, key_release, &en);
  mlx_loop(en.mlx.ptr);
  return (0);
}
