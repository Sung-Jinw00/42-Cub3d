/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:56:50 by gakarbou          #+#    #+#             */
/*   Updated: 2025/04/29 16:33:56 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_dist(int map[5][5], void *img, double degree)
{
	write(1, "GO\n", 3);
	double posX = 2.5, posY = 1.01 + degree;

	double dirX = 0, dirY = -1;
	double planeX = 0.66, planeY = 0;

	for (int x = 0; x < 1000; x++)
	{
		double cameraX = 2 * x / (double)1000 - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = (int)posX;
		int mapY = (int)posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX;
		double deltaDistY;
		if (rayDirX)
			deltaDistX = fabs(1 / rayDirX);
		else
			deltaDistX = 1e30;
		if (rayDirY)
			deltaDistY = fabs(1 / rayDirY);
		else
			deltaDistY = 1e30;
		double perpWallDist;

		int	stepX;
		int	stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (map[mapY][mapX])
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
		int lineHeight = (int)(1000 / perpWallDist);

		int drawStart = -lineHeight / 2 + 1000 / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + 1000 / 2;
		if (drawEnd >= 1000)
			drawEnd = 1000;
		int	color = 0xFF0000;
		if (side)
			color = 0x0000FF;
		draw_vert(x, drawStart, drawEnd, color, img);
	}
	return ;
}

void	rotate_yahoo(t_img *img, double degree)
{
	static int map[5][5] = {
		{1,1,1,1,1},
		{1,1,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1},
	};
	display_screen(map, img, degree);
}

int	raytest(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	//int		info[2];

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1000, 1000, "The Binding of Isaac : Twilight Princess HD Remastered + Funky Mode\n");
	mlx_img = NULL;
	//put_stored_image("assets/wall.xpm", mlx_ptr, mlx_win, mlx_img);
	//put_stored_image("assets/isaac.xpm", mlx_ptr, mlx_win, mlx_img);
	int	i = -1;
	double j = 0;
	while (1)
	{
		i++;
		if (i >= 80000)
		{
			if (mlx_img)
				mlx_destroy_image(mlx_ptr, mlx_img);
			mlx_img = mlx_new_image(mlx_ptr, 1000, 1000);
			j += 0.03;
			rotate_yahoo(mlx_img, j);
			mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 0);
			i = 0;
		}
	}
	return (0);
}
