/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:40:40 by marvin            #+#    #+#             */
/*   Updated: 2025/05/01 16:29:42 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	game->player.y = y;
	x = 0;
	while (!ft_strchr("NSEW", game->map.map_array[y][x]))
		x++;
	game->player.x = x;
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

void	actualise_player_pos(char **map_array, t_player p, t_player *ptr_p,
	int key)
{
	if (key == 'w')
	{
		p.x += p.direction_x * p.mvt_speed;
		p.y += p.direction_y * p.mvt_speed;
	}
	else if (key == 's')
	{
		p.x -= p.direction_x * p.mvt_speed;
		p.y -= p.direction_y * p.mvt_speed;
	}
	else if (key == 'a')
	{
		p.x -= p.direction_y * p.mvt_speed;
		p.y += p.direction_x * p.mvt_speed;
	}
	else if (key == 'd')
	{
		p.x += p.direction_y * p.mvt_speed;
		p.y -= p.direction_x * p.mvt_speed;
	}
	if (map_array[(int)p.y][(int)(p.x)] != '1')
	{
		ptr_p->x = p.x;
		ptr_p->y = p.y;
	}
}
