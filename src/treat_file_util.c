/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:53:48 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/24 21:07:15 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_elem(t_map *map, int elem)
{
	if (elem == 0)
		return (&map->no_path);
	else if (elem == 1)
		return (&map->so_path);
	else if (elem == 2)
		return (&map->we_path);
	else if (elem == 3)
		return (&map->ea_path);
	return (NULL);
}
