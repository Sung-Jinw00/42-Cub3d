/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:56:50 by gakarbou          #+#    #+#             */
/*   Updated: 2025/04/27 23:01:54 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*get_pos(void)
{
	int *dest;

	dest = malloc(sizeof(int) * 2);
	dest[0] = 256 * 5;
	dest[1] = 256 * 5;
	return (dest);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
    *(int *)pixel = color;
}

void	remove_bottom_half(void *mlx_img, int infos[2])
{
	int		i;
	int		j;

	j = -1;
	while (++j < infos[1])
	{
		i = -1;
		while (++i < infos[0])
		{
			if ((((infos[1] * i) + i) % (j + i + 1)) >= 20)
				put_pixel(mlx_img, i, j, 0);
		}
	}
}

void	get_dist(int map[5][5])
{
	double posX = 2.5, posY = 2.5;

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
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / dirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / dirY;
		printf("DIST = |%f| CAMX = |%f|\n", perpWallDist, cameraX);
	}
	return ;
}

void	rotate_yahoo(t_img *img, int degree)
{
	(void)img;
	(void)degree;
	static int map[5][5] = {
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1},
	};
	get_dist(map);
}

void	put_stored_image(char *filename, void *mlx_ptr, void *mlx_win, void *mlx_img)
{
	int		**frame_buffer;
	int		i;
	int		j;

	(void)mlx_win;
	frame_buffer = store_image(filename, mlx_ptr);
	j = -1;
	while (frame_buffer[++j])
	{
		i = -1;
		while (frame_buffer[j][++i] != -1)
			if (frame_buffer[j][i] >= 0)
				put_pixel(mlx_img, i, j, frame_buffer[j][i]);
	}
}

int	raytest(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	//int		info[2];

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1000, 1000, "The Binding of Isaac : Twilight Princess HD Remastered + Funky Mode\n");
	mlx_img = mlx_new_image(mlx_ptr, 1000, 1000);
	put_stored_image("assets/wall.xpm", mlx_ptr, mlx_win, mlx_img);
	put_stored_image("assets/isaac.xpm", mlx_ptr, mlx_win, mlx_img);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 0);
	rotate_yahoo(mlx_img, 0);
	while (1)
	{
			;
	}
	return (0);
}
