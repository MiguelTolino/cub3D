/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:02:25 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/26 11:35:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
  t_mlx mlx;
  t_cam cam;
  check_arg(argc, argv);
  read_config(argv[1]);
  
  cam = init();
  print_data(cam);
  create_window(&mlx);
  //gameloop(&mlx, cam);
  mlx_loop(mlx.ptr);
  return (0);
}
