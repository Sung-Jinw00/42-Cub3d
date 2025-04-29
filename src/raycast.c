/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:17:03 by gakarbou          #+#    #+#             */
/*   Updated: 2025/04/29 16:37:18 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_steps(t_raycast *infos, t_player *player)
{
	if (infos->ray_dir[0] < 0)
	{
		infos->steps[0] = -1;
		infos->side_dist[0] = (player->x - infos->map_pos[0])
			* infos->delta_dist[0];
	}
	else
	{
		infos->steps[0] = 1;
		infos->side_dist[0] = (infos->map_pos[0] + 1 - player->x)
			* infos->delta_dist[0];
	}
	if (infos->ray_dir[1] < 0)
	{
		infos->steps[1] = -1;
		infos->side_dist[1] = (player->y - infos->map_pos[1])
			* infos->delta_dist[1];
	}
	else
	{
		infos->steps[1] = 1;
		infos->side_dist[1] = (infos->map_pos[0] + 1 - player->y)
			* infos->delta_dist[1];
	}
}

static void	init_raycast_infos(t_game *game, t_raycast *infos, double cam_x)
{
	infos->map_pos[0] = (int)game->player->x;
	infos->map_pos[1] = (int)game->player->y;
	infos->ray_dir[0] = (game->directions[0] + game->plane[0]) * cam_x;
	infos->ray_dir[1] = (game->directions[1] + game->plane[1]) * cam_x;
	if (infos->ray_dir[0])
		infos->delta_dist[0] = fabs(1 / infos->ray_dir[0]);
	else
		infos->delta_dist[0] = 1e30;
	if (infos->ray_dir[1])
		infos->delta_dist[1] = fabs(1 / infos->ray_dir[1]);
	else
		infos->delta_dist[1] = 1e30;
	init_steps(infos, game->player);
}

static double	get_wall_dist(t_game *game, t_raycast *infos, double cam_x)
{
	init_raycast_infos(game, infos, cam_x);
	while (1)
	{
		if (infos->side_dist[0] < infos->side_dist[1])
		{
			infos->side_dist[0] += infos->delta_dist[0];
			infos->map_pos[0] += infos->steps[0];
			infos->side = 0;
		}
		else
		{
			infos->side_dist[1] += infos->delta_dist[1];
			infos->map_pos[1] += infos->steps[1];
			infos->side = 1;
		}
		if (game->map[infos->map_pos[1]][infos->map_pos[0]] != '0')
			break ;
	}
	if (!infos->side)
		return ((infos->map_pos[0] - game->player->x
				+ (1 - infos->steps[0]) / 2) / infos->ray_dir[0]);
	return ((infos->map_pos[1] - game->player->y
			+ (1 - infos->steps[1]) / 2) / infos->ray_dir[1]);
}

static void	draw_column(t_img *img, int x, int column_infos[3])
{
	column_infos[1]++;
	while (column_infos[0] != column_infos[1])
	{
		put_pixel(img, x, column_infos[0], column_infos[2]);
		column_infos[0]++;
	}
}

void	display_screen(t_game *game)
{
	t_raycast	infos;
	double		wall_dist;
	int			line_height;
	int			column_infos[3];
	int			x;

	x = -1;
	while (++x < 1000)
	{
		wall_dist = get_wall_dist(game, &infos, 2 * x / 1000.0 - 1);
		line_height = (int)(1000 / wall_dist);
		column_infos[0] = ft_min(-line_height / 2 + 1000 / 2, 0);
		column_infos[1] = ft_max(line_height / 2 + 1000 / 2, 1000);
		if (infos.side)
			column_infos[2] = 0x0000FF;
		else
			column_infos[2] = 0xFF0000;
		draw_column(game->mlx->img, x, column_infos);
	}
}
