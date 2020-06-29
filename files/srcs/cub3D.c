/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:02:25 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/29 13:58:02 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
  t_mlx mlx;
  t_cam cam;
  t_engine en;
  check_arg(argc, argv);
  read_config(argv[1]);
  
  init(&en);
  print_data(en);
  create_window(&mlx);
  gameloop(&mlx, en);
  mlx_loop(mlx.ptr);
  return (0);
}
