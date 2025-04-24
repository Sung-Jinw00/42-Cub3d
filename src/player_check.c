/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:40:40 by marvin            #+#    #+#             */
/*   Updated: 2025/04/23 16:40:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	only_one_player(char *map)
{
	int		i;
	size_t	nb_players;

	i = 0;
	nb_players = 0;
	while (map[i])
	{
		if (ft_strchr("NSEW", map[i]))
			nb_players++;
		if (nb_players > 1)
		{
			write(2, "Error\nMore than one player.\n", 27);
			return (0);
		}
		i++;
	}
	if (nb_players == 1)
		return (1);
	write(2, "Error\nNo player on the map.\n", 28);
	return (0);
}
