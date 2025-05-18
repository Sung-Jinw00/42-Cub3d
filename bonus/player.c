/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:40:40 by marvin            #+#    #+#             */
/*   Updated: 2025/05/14 18:26:15 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_camera(t_game *game, char dir)
{
	t_player	*player;

	player = &game->player;
	if (dir == 'W' || dir == 'E')
	{
		player->direction_x = 1 - (2 * (dir == 'W'));
		player->plane_y = 0.66;
		if (dir == 'W')
			player->plane_y = -0.66;
	}
	else
	{
		player->direction_y = 1 - (2 * (dir == 'N'));
		player->plane_x = 0.66;
		if (dir == 'S')
			player->plane_x = -0.66;
	}
	player->ray_dir_x[0] = player->direction_x - player->plane_x;
	player->ray_dir_x[1] = (player->direction_x + player->plane_x)
		- player->ray_dir_x[0];
	player->ray_dir_y[0] = player->direction_y - player->plane_y;
	player->ray_dir_y[1] = (player->direction_y + player->plane_y)
		- player->ray_dir_y[0];
}

static void	get_player_infos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (!ft_strchr(game->map.map_array[y], 'N')
		&& !ft_strchr(game->map.map_array[y], 'S')
		&& !ft_strchr(game->map.map_array[y], 'E')
		&& !ft_strchr(game->map.map_array[y], 'W'))
		y++;
	game->player.y = y + 0.5001;
	x = 0;
	while (!ft_strchr("NSEW", game->map.map_array[y][x]))
		x++;
	game->player.x = x + 0.5001;
	init_camera(game, game->map.map_array[y][x]);
	game->map.map_array[(int)game->player.y][(int)game->player.x] = '0';
	game->map.map[(int)((game->player.y * game->map.w_map)
			+ game->player.x)] = '0';
}

int	only_one_player(t_game *game)
{
	int		i;
	size_t	nb_players;

	i = 0;
	nb_players = 0;
	while (game->map.map[i])
	{
		if (ft_strchr("NSEW", game->map.map[i]))
			nb_players++;
		if (nb_players > 1)
		{
			ft_error("More than one player.\n");
			return (0);
		}
		i++;
	}
	if (nb_players == 1)
	{
		get_player_infos(game);
		game->player.mvt_speed = SPEED;
		return (1);
	}
	ft_error("No player on the map.\n");
	return (0);
}

static void	compute_movement(t_player *cpy, int key)
{
	if (key == 'w')
	{
		cpy->x += cpy->direction_x * cpy->mvt_speed;
		cpy->y += cpy->direction_y * cpy->mvt_speed;
	}
	else if (key == 's')
	{
		cpy->x -= cpy->direction_x * cpy->mvt_speed;
		cpy->y -= cpy->direction_y * cpy->mvt_speed;
	}
	else if (key == 'd')
	{
		cpy->x -= cpy->direction_y * cpy->mvt_speed;
		cpy->y += cpy->direction_x * cpy->mvt_speed;
	}
	else if (key == 'a')
	{
		cpy->x += cpy->direction_y * cpy->mvt_speed;
		cpy->y -= cpy->direction_x * cpy->mvt_speed;
	}
}

void	actualise_player_pos(char **map_array, t_player *player, int key)
{
	t_player	cpy;

	cpy = *player;
	compute_movement(&cpy, key);
	if (map_array[(int)player->y][(int)(cpy.x)] != '1')
		player->x = cpy.x;
	if (map_array[(int)cpy.y][(int)(player->x)] != '1')
		player->y = cpy.y;
}
