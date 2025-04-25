/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:29:31 by gakarbou          #+#    #+#             */
/*   Updated: 2025/04/24 15:11:37 by gakarbou         ###   ########.fr       */
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

void	init_steps(int steps[2], double side_dist[2], double angle)
{
	double	delta[2];
	double	ray_dir[2];

	ray_dir[0] = (-1 + 0 * (2 * angle / (double)3000));
	ray_dir[1] = (0 + 0.66 * (2 * angle / (double)3000));
	if (ray_dir[0])
		delta[0] = fabs(1 / ray_dir[0]);
	else
		delta[0] = 1e30;
	if (ray_dir[1])
		delta[1] = fabs(1 / ray_dir[1]);
	else
		delta[1] = 1e30;
	if (ray_dir[0] < 0)
	{
		steps[0] = -1;
		side_dist[0] = (5 - 10) * delta[0];
	}
	else
	{
		steps[0] = 1;
		side_dist[0] = (10 + 1 - 5) * delta[0];
	}
	if (ray_dir[1] < 0)
	{
		steps[1] = -1;
		side_dist[1] = (5 - 10) * delta[1];
	}
	else
	{
		steps[1] = 1;
		side_dist[1] = (10 + 1 - 5) * delta[1];
	}
}

int	get_wall_distance(int map[10][10], int *pos, int angle)
{
	int		map_pos[2];
	int		step[2];
	double	delta_dist[2];
	double	side_dist[2];
	double	side;

	map_pos[0] = 5;
	map_pos[1] = 5;
	init_steps(step, side_dist, angle);
	while (1)
	{
		if (side_dist[0] < side_dist[1])
		{
			side_dist[0] += delta_dist[0];
			map_pos[0] += step[0];
			side = 0;
		}
		else
		{
			side_dist[1] += delta_dist[1];
			map_pos[1] += step[1];
			side = 1;
		}
		if (map[map_pos[1]][map_pos[0]])
			break ;
	}
	if (side)
		return (side_dist[0] - side_dist[1]);
	return (side_dist[1] - side_dist[0]);
}

void	rotate_yahoo(t_img *img, int degree)
{
	int	*pos;
	int	i;
	int	dist;
	static int map[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,1},
		{1,0,1,1,0,0,0,0,0,1},
		{1,0,1,1,0,0,0,0,0,1},
		{1,0,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
	pos = get_pos();
	i = -1;
	while (++i < 300)
	{
		dist = get_wall_distance(map, pos, i);
		printf("DIST = |%d|\n", dist);
	}
}

void	put_stored_image(char *filename, void *mlx_ptr, void *mlx_win, void *mlx_img)
{
	int		**frame_buffer;
	int		i;
	int		j;

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

void	put_resized_image(char *filename, void *mlx_ptr, void *mlx_win, void *mlx_img)
{
	int	new_dim[2];

	new_dim[0] = 256;
	new_dim[1] = 256;
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	//int		info[2];

	(void)argc;
	(void)argv;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 3000, 3000, "The Binding of Isaac : Twilight Princess HD Remastered + Funky Mode\n");
	mlx_img = mlx_new_image(mlx_ptr, 3000, 3000);
	put_stored_image("assets/wall.xpm", mlx_ptr, mlx_win, mlx_img);
	put_stored_image("assets/isaac.xpm", mlx_ptr, mlx_win, mlx_img);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 0);
	int i = -1;
	while (1)
	{
		i++;
		//rotate_yahoo(mlx_img, 0);
	}
	return (0);
}
