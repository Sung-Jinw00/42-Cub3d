/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:43:42 by marvin            #+#    #+#             */
/*   Updated: 2025/04/23 16:43:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	if (map->no_path)
		ft_free(&map->no_path);
	if (map->so_path)
		ft_free(&map->so_path);
	if (map->we_path)
		ft_free(&map->we_path);
	if (map->ea_path)
		ft_free(&map->ea_path);
	if (map->map)
		ft_free(&map->map);
}
