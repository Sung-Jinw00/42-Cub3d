/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:49:22 by gakarbou          #+#    #+#             */
/*   Updated: 2025/05/08 20:09:29 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	init_steps(t_raycast *infos, t_player *player)
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
		infos->side_dist[0] = (infos->map_pos[0] + 1.0 - player->x)
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
		infos->side_dist[1] = (infos->map_pos[1] + 1.0 - player->y)
			* infos->delta_dist[1];
	}
}

static inline void	init_raycast_infos(t_player *player, t_raycast *infos,
		double cam_x)
{
	infos->map_pos[0] = (int)player->x;
	infos->map_pos[1] = (int)player->y;
	infos->ray_dir[0] = player->direction_x
		+ player->plane_x * cam_x;
	infos->ray_dir[1] = player->direction_y
		+ player->plane_y * cam_x;
	if (infos->ray_dir[0])
		infos->delta_dist[0] = fabs(1 / infos->ray_dir[0]);
	else
		infos->delta_dist[0] = 1e30;
	if (infos->ray_dir[1])
		infos->delta_dist[1] = fabs(1 / infos->ray_dir[1]);
	else
		infos->delta_dist[1] = 1e30;
	init_steps(infos, player);
}

double	get_wall_dist(t_game *game, t_raycast *infos, double cam_x, char **map)
{
	int		is_vert;

	init_raycast_infos(&game->player, infos, cam_x);
	while ((map[infos->map_pos[1]])[infos->map_pos[0]] != '1')
	{
		is_vert = infos->side_dist[0] >= infos->side_dist[1];
		infos->side_dist[is_vert] += infos->delta_dist[is_vert];
		infos->map_pos[is_vert] += infos->steps[is_vert];
		infos->side = is_vert;
	}
	if (!infos->side)
		return ((infos->map_pos[0] - game->player.x
				+ (1 - infos->steps[0]) / 2) / infos->ray_dir[0]);
	return ((infos->map_pos[1] - game->player.y
			+ (1 - infos->steps[1]) / 2) / infos->ray_dir[1]);
}
