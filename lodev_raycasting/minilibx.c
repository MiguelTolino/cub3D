/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 10:27:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/06/30 19:17:49 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/srcs/cub3D.h"

int main()
{
	int choice;
	int i, j, k;
	int w, h;
	int endian, bpp, size_line;
	w = 600;
	h = 400;

	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, w, h, "Win");
	void *img_ptr = mlx_new_image(mlx_ptr, w, h);
	char *data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);

	printf("%s", data);

	printf("Which shape do you want to print?\n");
	printf("1.Rombo\n");
	printf("2.Square\n");
	printf("3.Triangle\n");
	printf("Your choice: ");
	scanf("%i", &choice);

	if (choice == 1)
	{
		j = h / 2;
		i = 0;
		k = h / 2;

		while (j > 0)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j--, 255);
			mlx_pixel_put(mlx_ptr, win_ptr, i++, k++, 255);
		}
		while (j < h / 2)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j++, 255);
			mlx_pixel_put(mlx_ptr, win_ptr, i++, k--, 255);
		}
	}
	if (choice == 2)
	{
		i = w / 3;
		while (i < 2*w/3)
		{
			j = h/3;
			k = 2*h/3;
			if (i == w/3 || i == 2*w/3 - 1)
			{
				while (j < 2*h/3)
				{
					mlx_pixel_put(mlx_ptr, win_ptr, i, j++, 255);
				}
			}
			else
			{
				mlx_pixel_put(mlx_ptr, win_ptr, i++, j, 255);
				mlx_pixel_put(mlx_ptr, win_ptr, i++, k, 255);
			}
			
			
		}
		
	}
	

	mlx_loop(mlx_ptr);

	return (0);
}
