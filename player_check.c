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
	while (map[i])
	{
		if (multi_charcmp(map[i], "NSEW"))
			nb_players++;
		if (nb_players > 1)
		{
			ft_write(2, "Error\nMore than one player.\n");
			return (0);
		}
		i++;
	}
	if (nb_players == 1)
		return (1);
	ft_write(2, "Error\nNo player on the map.\n");
	return (0);
}
