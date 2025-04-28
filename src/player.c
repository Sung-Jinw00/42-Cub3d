/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:40:40 by marvin            #+#    #+#             */
/*   Updated: 2025/04/28 18:54:47 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_player_infos(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (!ft_strchr(map->map_array[y], 'N')
		&& !ft_strchr(map->map_array[y], 'S')
		&& !ft_strchr(map->map_array[y], 'E')
		&& !ft_strchr(map->map_array[y], 'W'))
		y++;
	map->player.y = y;
	x = 0;
	while (!ft_strchr("NSEW", map->map_array[y][x]))
		x++;
	map->player.x = x;
	map->map_array[(int)map->player.y][(int)map->player.x] = '0';
	map->map[(int)((map->player.y * map->w_map) + map->player.x)] = '0';
}

int	only_one_player(t_map *map)
{
	int		i;
	size_t	nb_players;

	i = 0;
	nb_players = 0;
	while (map->map[i])
	{
		if (ft_strchr("NSEW", map->map[i]))
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
		get_player_infos(map);
		map->player.move_unit = 1.0 / 15.0;
		return (1);
	}
	ft_error("No player on the map.\n");
	return (0);
}

int	is_valid_move(char **map_array, t_player p, int key)
{
	if (key == XK_w)
		return (map_array[(int)(p.y - p.move_unit)][(int)p.x] != '1');
	else if (key == XK_a)
		return (map_array[(int)p.y][(int)(p.x - p.move_unit)] != '1');
	else if (key == XK_s)
		return (map_array[(int)(p.y + p.move_unit)][(int)p.x] != '1');
	else if (key == XK_d)
		return (map_array[(int)p.y][(int)(p.x + p.move_unit)] != '1');
	return (0);
}

void	actualise_player_pos(t_player *p, int key)
{
	if (key == XK_w)
		p->y -= p->move_unit;
	else if (key == XK_a)
		p->x -= p->move_unit;
	else if (key == XK_s)
		p->y += p->move_unit;
	else if (key == XK_d)
		p->x += p->move_unit;
}
